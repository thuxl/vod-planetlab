#include "peer.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int peer::current_T = 0;
double   peer::myoutput_bw = 0;
int 	 peer::mypeerid = 0;

peer::peer (void)
{
	myoutput_bw = 0;
	for (int i=0; i<NUM_OF_T; i++)
	{
		req_segid[i] = -1;
		req_segbw[i] = 0;
	}
}


void peer::set_outband(const double mybw, const double* peersbw)
{
	myoutput_bw = mybw;
	current_upbw = mybw;
	being_used_duration = 0;
	for (int i=0; i<NUM_OF_PEERS; i++)
		peer_output_bw[i] = peersbw[i];
}


void peer::set_reqs(const int *reqids, const double *bw)
{
	for (int i=0; i<NUM_OF_T; i++)
	{
		req_segid[i] = reqids[i];
		req_segbw[i] = bw[i];
	}
}

void peer::set_peerid(int id)
{
	mypeerid = id;
	peers[id].id = id;
	node::myid = id;
}

void* peer::listen_thread(void* ptr)
{
		if(!Init_Listen()){
			MY_PRINT("listen fail, wait 10s");
			return 0;
		}
		if (!peer_Listen_cmd())
			return 0;
		Stop_listen();

		pthread_exit(NULL);
}

int peer::peer_Listen_cmd()
{
    int     	clie_addr_len;
	int 		pid;
	int			accept_sock [NUM_OF_PEERS];
	pthread_t   pthid [NUM_OF_PEERS];
	int     	i_of_thread = 0;
    struct sockaddr_in     rec_clie_addrs[NUM_OF_PEERS];
	
	while (To_listen) { //a connection sends only one cmd.
	
		clie_addr_len = sizeof(rec_clie_addrs[i_of_thread]);


		//no block rec
		struct timeval tv;
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		fd_set  rset;
		FD_ZERO(&rset);
		FD_SET(rec_sock_id, &rset);
		int nready = select(rec_sock_id+ 1, &rset, NULL, NULL, &tv);
		if (nready < 0) {
			perror("select err.");
   	     	MY_PRINT("select err");
			continue;
		} else if (nready == 0) {
   		    MY_PRINT("timeout ");
			continue;
		}

		accept_sock[i_of_thread ] = -1;
		if (FD_ISSET(rec_sock_id, &rset))
    		accept_sock[i_of_thread ] = accept(rec_sock_id, (struct sockaddr *)&rec_clie_addrs[i_of_thread], (socklen_t*)&clie_addr_len);
    	if (accept_sock[i_of_thread ]< 0) {
			MY_PRINT("Accept socket failed:"<< accept_sock[i_of_thread ]);
			continue;
    	}

		//char client_ip[30] = {0};
		//strcpy(client_ip,  inet_ntoa(rec_clie_addr.sin_addr) );

		//pthread_create(&pthid[i_of_thread ], NULL, Parse_cmd , &accept_sock[i_of_thread]);
		//Parse_cmd (accept_sock[i_of_thread]);
		int     	sock = accept_sock[i_of_thread];
	    char                   buf[MAXLINE], buf2[MAXLINE], word[30];
   	 	int                    recv_len=0;
   	 	int                    write_leng;
		int 		wordlen=0, bufidx=0;
    	bzero(buf, MAXLINE);
    	bzero(buf2, MAXLINE);

		//no block rec
		struct timeval tv1;
		tv1.tv_sec = 5;
    	tv1.tv_usec = 0;
		fd_set  rset1;
		FD_ZERO(&rset1);
		FD_SET(sock, &rset1);
		int nready1 = select(sock + 1, &rset1, NULL, NULL, &tv1);
		if (nready1 < 0) {
			perror("select err.");
        	MY_PRINT("select err");
			close(sock);
			continue;

		} else if (nready1 == 0) {
        	MY_PRINT("timeout ");
			close(sock);
			continue;
		}
	
		if (FD_ISSET(sock, &rset1))
    		recv_len = recv(sock, buf, MAXLINE, 0);
        
		if(recv_len <= 0) {
			MY_PRINT("Recieve Data From Server Failed!");
			close(sock);
			continue;
    	}
/*
 * cmd intro.
 * peerid startreq t : may i start req in slot t?
 *    for server
 *      return 1 state1 state2 ...stateN : ok , state1 means peer1's active.
 *      return 0 state1 state2 ...stateN : no
 * peerid finishreq t : i finished req in slot t.
 *    for server, return 1 means ok, 
 *                return 0 means fail.
 * peerid updatecache peerid seg_id1 seg_id2 ... : peerid has segs.
 *    for all, return  1 or 0.
 * peerid getsegs bw duration: i need segs for duration second.
 *    for peers
 * 		return 1 : means successful.
 * 		return 0 bw : means fail and i can provide bw at most.
 *    for server
 * 		only return 1 : means successful. no matter how much bw is required. 
 * peerid updateupband bw : peerid has upband bw.
 *    for all, return 1 or 0.
 * -1 close : exit.
 *    server informs peers to close, return 1 or 0.
 * -1 heartbeat : to validate peers whether active.
 *    for peers, return 1, active
 *               no return or return 0, die.
 * -1 peerstates state1 state2 ... : state1 is of bool type, 0 means dead while 1 means active.
 *    for peers, return 0 or 1.
 * peerid test hello
 *    from peerid to server, return 0 or 1.
 * peerid complete peerid : peerid has been finished its requirement.
 * peerid setupband bw : update peer upband, bw is in kbps.
 * peerid setT T : update T for peer, T is time periods.
 * peerid setrequire segid1 segid2 ... segidT : T is time periods.
 */
    //MY_PRINT("peer::rec:["<<buf << "] from ["<<ip <<"]");
		strcpy(buf2, buf);
	
		bzero(word, 30); wordlen=0; bufidx=0;
		while (buf[bufidx] != 0 && buf[bufidx] != ' ')
			word[wordlen++] = buf[bufidx++];
		int frompeerid=atoi(word);
		bzero(word, 30); wordlen=0; bufidx++;
		while (buf[bufidx] != 0 && buf[bufidx] != ' ')
			word[wordlen++] = buf[bufidx++];
		if (!strcmp("updatecache", word)){
			//updatecache peerid seg_id1 seg_id2 ... : peerid has segs.
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			int peerid=atoi(word);
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			int segid=atoi(word);
			send(sock, "1", 2, 0);
			close(sock);
    		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"]"
					<<" updatecache, peerid="<< peerid<<", segid="<< segid);
			cache[peerid][segid] = true;

		}
		else if (!strcmp("getsegs", word)){
			double reqbw;
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			sscanf(word, "%lf", &reqbw);
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			sscanf(word, "%lf", &recovery_time );
	
			if (reqbw > myoutput_bw){ //fail
				char ret[20]; bzero(ret, 20);
				sprintf(ret, "0 %f", myoutput_bw);
				send(sock, ret, strlen(ret)+1, 0);//this may block the listen procession.
				close(sock);

   		 		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"] fail");
				//int s=sock;
				//pthread_t pid;
				//pthread_create(&pid, NULL, send_fail, &s);
				//send(sock, ret, strlen(ret)+1, 0);//this may block the listen procession.
			}
			else{//success
				send(sock, "1", 2, 0);
				close(sock);
				//update my upband, and inform other peers and server
				myoutput_bw -= reqbw ;
				recovery_bw += reqbw ;
	
   		 		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"]"
						<<" success peer ["<< frompeerid<<"] reqbw["<<reqbw <<"] recovery_bw["
						<< recovery_bw<<"] reqtime["<<recovery_time <<"] success, upband["<< myoutput_bw <<"]");
				pthread_t pid;
				pthread_create(&pid, NULL, recovery_upband, NULL);
				//recovery_upband(NULL);

			}
		}
		else if (!strcmp("updateupband", word)){
    		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"] ");
			double new_bw;
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			sscanf(word, "%lf", &new_bw);
			send(sock, "1", 2, 0);
			close(sock);
			peers[frompeerid].upband = new_bw;
		
		}
		else if (!strcmp("close", word)){
    		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"] ");
			send(sock, "1", 2, 0);
			close(sock);
			node::To_listen = false;
		}
    	else if (!strcmp("heartbeat", word)){
    		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"] ");
			send(sock, "1", 2, 0);
			close(sock);
		}
		else if (!strcmp("peerstates", word)){
    		MY_PRINT("peer::rec:["<<buf2 << "] from ["<<frompeerid <<"] ");
			for (int pid=0; pid<NUM_OF_PEERS; pid++)
			{
				bzero(word, 30); wordlen=0; bufidx++;
				while (buf[bufidx] != 0 && buf[bufidx] != ' ')
					word[wordlen++] = buf[bufidx++];
				int state=atoi(word);
				//MY_PRINT("state pid["<<pid <<"]:["<<state <<"]");
				peers[pid].active = state;
			}
			send(sock, "1", 2, 0);
			close(sock);
		}
		else
			close(sock);


		i_of_thread++;
		i_of_thread = i_of_thread % NUM_OF_PEERS;
	}
	
	return 1;
}



int peer::peersend_cmd(node_p &p, char *cmd)
{

	int ret;

	Set_DestIP(p.ip);
	Set_DestPORT(p.port);

	if (!Init_send()){
		MY_PRINT("fail send["<<cmd <<"] to peer["<<p.id <<"] ip["<<p.ip <<"] port["<<p.port <<"]");
		return 0;
	}
	ret = Send_cmd(cmd);
	MY_PRINT("send["<<cmd <<"] to peer["<<p.id <<"] ip["<<p.ip <<"] port["<<p.port <<"], return ["<<ret <<"]");
	
	Stop_cmd();
 
	return ret;
}

int peer::peersend_cmd(node_p &p, char *cmd, char *ret_str)
{

	int ret;

	Set_DestIP(p.ip);
	Set_DestPORT(p.port);

	if (!Init_send())
		return 0;
	MY_PRINT("send["<<cmd <<"] to peer["<<p.id <<"] ip["<<p.ip <<"] port["<<p.port <<"]");
	ret = Send_cmd(cmd, ret_str);
	
	Stop_cmd();
 
	return ret;
}

void peer::broadcast_cache(int peerid, int segid)
{
	char tmpcmd[MAXLINE ];
	bzero(tmpcmd, MAXLINE );
	sprintf(tmpcmd, "%d updatecache %d %d", mypeerid, peerid, segid);
	cache[peerid][segid] = true;
	for (int i=0; i < NUM_OF_PEERS; i++){
		if (i != mypeerid && peers[i].active > 0)
			peersend_cmd(peers[i], tmpcmd);
	}
	peersend_cmd(servernode, tmpcmd);

}

void* peer::broadcast_myupband(void* ptr)
{
	char tmpcmd[MAXLINE ];
	bzero(tmpcmd, MAXLINE );
	sprintf(tmpcmd, "%d updateupband %lf", mypeerid, myoutput_bw);
	MY_PRINT(tmpcmd);
	for (int i=0; i < NUM_OF_PEERS; i++){
		if (i != mypeerid && peers[i].active > 0)
			peersend_cmd(peers[i], tmpcmd);
	}
	peersend_cmd(servernode, tmpcmd);

}

void* peer::recovery_upband(void* ptr)
{
	
	broadcast_myupband(ptr); //this may block the listen procession.
	usleep((int)(recovery_time * 1000000));
	myoutput_bw += recovery_bw ;
	MY_PRINT("recovery, wait["<<recovery_time <<"]s, upband["<< myoutput_bw <<"] recovery_bw["<< recovery_bw <<"] ");
	recovery_bw =0;
	broadcast_myupband(ptr);

	pthread_detach(pthread_self());
	pthread_exit(NULL);

}

void* peer::send_fail(void* sock)
{
	int ss = *(int *)sock;
	char ret[20]; bzero(ret, 20);
	sprintf(ret, "0 %f", myoutput_bw);
	send(ss, ret, strlen(ret)+1, 0);//this may block the listen procession.
}


int peer::testrun()
{
	int ret;
	char cmd[50] = {0};
	char ret_str[200] = {0};

	sprintf(cmd, "%d test hello", mypeerid);

	Set_DestIP(servernode.ip);
	Set_DestPORT(servernode.port);

	MY_PRINT("test Init_send");
	if (!Init_send())
		return 0;
	MY_PRINT("test send["<<cmd <<"] to server["<<servernode.id <<"] ip["<<servernode.ip <<"] port["<<servernode.port <<"]");
	ret = testSend_cmd(cmd, ret_str);
	MY_PRINT("test rec feedback ["<<ret_str <<"] ret["<< ret <<"]");
	
	Stop_cmd();
 
	return ret;

}

int peer::run()
{
	int granted=0;
	while (current_T < NUM_OF_T)
	{
		int req_meeted = 0;
		char cmd[MAXLINE - 1] = {0}, retcmd[MAXLINE ];
		req_meeted = 0;
		bzero(cmd, MAXLINE - 1);
		bzero(retcmd, MAXLINE );
		sprintf(cmd, "%d startreq %d", mypeerid, current_T);
		//itoa(current_T, tmp_t, 10);
		//strcat(cmd, tmp_t);
		//printf("peer[%d], current t[%d] upband[%f] ===============\n", mypeerid, current_T, myoutput_bw);
		MY_PRINT("peer["<< mypeerid <<"], current t["<< current_T<<"] reqsegid["<<req_segid[current_T]  <<"] reqbw ["
				<< req_segbw[current_T]<<"] upband["<< myoutput_bw <<"] grant["<< granted <<"]===============");
		if (granted == 0)
		while ( !peersend_cmd(servernode, cmd, retcmd) ) {
			//printf("startreq, not granted, wait 10s\n", current_T);
			MY_PRINT("startreq, t["<< current_T <<"] not granted, wait 10s, ret["<< retcmd <<"]");
			for (int pid=0; pid<NUM_OF_PEERS; pid++)
				peers[pid].active = retcmd[pid*2] - '0';
			bzero(retcmd, MAXLINE );
			sleep(10); //in second; usleep is in us;
		}
		granted  = 1;
		MY_PRINT("granted ["<<granted <<"] req_meeted ["<< req_meeted <<"]");

		if (req_segid[current_T] != -1){
			provider_list.clear();
			int reqid = req_segid[current_T];
			double reqbw = req_segbw[current_T];
			double reqtime = (double) MEM_OF_SEG / reqbw;
			double peer_total_bw = 0;
			for (int i=0; i < NUM_OF_PEERS; i++){
				if (cache[i][reqid]){
					if (i == mypeerid) {
						req_meeted = 1;
						break;
					}
					else if ( peers[i].active > 0 && peers[i].upband >= reqbw){
						provider_list.clear();
						provider_list.push_back(provider(i, reqbw, reqtime));
						if (send_reqs(reqid )) {
							sleep (int (reqtime)); //emulating the transmissong of seg to me. 
							MY_PRINT("peer["<<i <<"] meet my require ["<< req_segbw[current_T]<<"], broadcast.");
							broadcast_cache(mypeerid, reqid);
							req_meeted = 1;
							break;
						}
						else { //the upbands of other peers have been changed.
							i = 0;
							peer_total_bw = 0;
							provider_list.clear();
							continue;
						}
					}
					else if (peers[i].active > 0 && peers[i].upband > 0.001){
						peer_total_bw += peers[i].upband;
						if (peer_total_bw  >= reqbw){
							provider_list.push_back(provider(i, peers[i].upband - (peer_total_bw - reqbw), reqtime));
							if (send_reqs(reqid )) {
								sleep (int (reqtime)); //emulating the transmissong of seg to me. 
								MY_PRINT(provider_list.size()<< " peers meet my require ["<< req_segbw[current_T] <<"], broadcast.");
								broadcast_cache(mypeerid, reqid);
								req_meeted = 1;
								break;
							}
							else { //the upbands of other peers have been changed.
								i = 0;
								peer_total_bw = 0;
								provider_list.clear();
								continue;
							}
						}
						else
							provider_list.push_back(provider(i, peers[i].upband, reqtime));
					}
				}//has seg
			}//for

		
			MY_PRINT("for over, granted ["<<granted <<"] req_meeted ["<< req_meeted <<"]");
			if (req_meeted == 0){
				//peer_total_bw += servernode.upband;
				//if (peer_total_bw >=  reqbw)
					//provider_list.push_back(provider(-1, servernode.upband - (peer_total_bw - reqbw), reqtime));
				//else
					//provider_list.push_back(provider(-2, reqbw - peer_total_bw , reqtime)); //-2 means to force server to provide bw no matter what it can offer.
				provider_list.push_back(provider(-1, reqbw - peer_total_bw , reqtime)); //-1 means to force server to provide bw no matter how much it can offer.
				if (send_reqs(reqid )) {
					sleep (int (reqtime)); //emulating the transmissong of seg to me. 
					MY_PRINT(provider_list.size()<< " peers and server meet my require ["<< req_segbw[current_T] <<"], broadcast");
					broadcast_cache(mypeerid, reqid);
					req_meeted = 1;
				}
				else { //cannot be met.
					peer_total_bw = 0;
					provider_list.clear();
	    			granted = 1;
					continue;
				}
			}
	    	

		}
		
		MY_PRINT("3 granted ["<<granted <<"] req_meeted ["<< req_meeted <<"]");
		granted = 0;
		bzero(cmd, MAXLINE - 1);
		sprintf(cmd, "%d finishreq %d", mypeerid, current_T);
		while ( !peersend_cmd(servernode, cmd) )
			sleep(5);
		current_T++;

	}
	
		
	//node::To_listen = false; //no need to stop, leave it to listen thread for close cmd.
	
	return 1;
}


int peer::send_reqs(int segid)
{
	char cmd[MAXLINE];
	char cmd_ret[MAXLINE];
	int ret;

	//provider_list.push_back(provider(i, peers[i].upband, reqtime));
	//int  peerid; //-1 is server, 0-n are peers.
	//double  provided_bw;
	//double  duration;

	for (vector<provider>::iterator pro = provider_list.begin(); pro != provider_list.end(); ++pro ){
		bzero(cmd, MAXLINE);
		bzero(cmd_ret, MAXLINE);
		sprintf(cmd,  "%d getsegs %f %f", mypeerid, pro->provided_bw, pro->duration);
		if (pro->peerid != -1){
			if ( !peersend_cmd(peers[pro->peerid], cmd, cmd_ret) ){
				//failed
				double new_upbw;
				sscanf(cmd_ret, "%lf", &new_upbw);
				peers[pro->peerid].upband = new_upbw;
				MY_PRINT("Opps, peer ["<< pro->peerid<<"] fail meet my need, its new upbw ["<<new_upbw <<"]");
				return 0;
			}
			//else //success
		}
		else //for server
			peersend_cmd(servernode, cmd, cmd_ret);
	}
	return 1;
}

void* peer::Parse_cmd(void* psock)
{}
