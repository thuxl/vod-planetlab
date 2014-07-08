#include "server.h"
#include <unistd.h>
#include <string.h>

#include <iostream>
using namespace std;

int      server::num_of_completed_peers = 0;
int 	 server::global_T = 0;
double   server::remain_upbw = 0;
double   server::myoutput_bw = 0;
double   server::fail_bw[NUM_OF_T+1][NUM_OF_PEERS];
int      server::num_of_active_peers = NUM_OF_PEERS;
char     server::freshstates[MAXLINE];
pthread_mutex_t      server::mutex;
pthread_spinlock_t   server::spinlock;
bool     server::fin[NUM_OF_PEERS][NUM_OF_T+1] = {0};
int      server::failtime=0;
int 	 server::successtime=0; 
int 	 server::recoveryn=0;

server::server (void)
{
	server::myoutput_bw = 0 ;
	servernode.upband = 0;
	for (int t = 0; t<NUM_OF_T; t++)
		for (int p = 0; p<NUM_OF_PEERS; p++)
			fail_bw[t][p] = 0;
}


void server::set_serverid(int sid)
{
	servernode.id = sid;
	node::myid = sid;
}

void server::set_server_upband(double bw) //in kbps
{
	servernode.upband = bw;
	server::myoutput_bw = bw ;
	server::remain_upbw = bw;
}


int server::Listen_cmd()
{
    int     	clie_addr_len;
	int 		pid;
	int			accept_sock [NUM_OF_PEERS] = {0};
	pthread_t   pthid [NUM_OF_PEERS];
	int     	i_of_thread = 0;
    struct sockaddr_in     rec_clie_addrs[NUM_OF_PEERS];

	while (To_listen) { //a connection sends only one cmd.
	
		clie_addr_len = sizeof(rec_clie_addrs[i_of_thread]);


		//no block rec
		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		fd_set  rset;
		FD_ZERO(&rset);
		FD_SET(rec_sock_id, &rset);
		int nready = select(rec_sock_id+ 1, &rset, NULL, NULL, &tv);
		if (nready < 0) {
			perror("select err.");
   	     	MY_PRINT("select err");
			//close(rec_sock_id);
			//if(!Init_Listen())
				//return 0;
			continue;
		} else if (nready == 0) {
   		    MY_PRINT("timeout,  num_of_active ["<< num_of_active_peers <<"], t ["<< global_T <<"] remainbw "<< myoutput_bw 
					<<" failt["<< failtime<<"] succ["<< successtime<<"] recovn["<< recoveryn<<"] init upbw["<< servernode.upband<<"]");
			//close(rec_sock_id);
			if (server::global_T >= NUM_OF_T
					&& myoutput_bw > (double) servernode.upband - (double) 10.1
					//&& myoutput_bw > (double)  10.1
					/*&& num_of_active_peers ==0*/){
					broadcast_close();
					node::To_listen = false;
					recordfail();
					break;
			}
			continue;
		}

    	if (accept_sock[i_of_thread ]> 0) {
			close(accept_sock[i_of_thread ]);
			accept_sock[i_of_thread ] = -1;
		}
		//if (FD_ISSET(rec_sock_id, &rset))
    		accept_sock[i_of_thread ] = accept(rec_sock_id, (struct sockaddr *)&rec_clie_addrs[i_of_thread], (socklen_t*)&clie_addr_len);
    	if (accept_sock[i_of_thread ]< 0) {
			MY_PRINT("Accept socket failed:"<< accept_sock[i_of_thread ]);
			close(accept_sock[i_of_thread ]);
			continue;
    	}

		
		//pthread_create(&pthid[i_of_thread ], NULL, Parse_cmd , &accept_sock[i_of_thread]);
		int     	sock = accept_sock[i_of_thread];
	    char    	buf[MAXLINE], buf2[MAXLINE], word[30];
   	 	int     	recv_len=0, wordlen, bufidx;
   	 	int     	write_leng;
    	bzero(buf, MAXLINE);
    	bzero(buf2, MAXLINE);

		//no block rec
		struct timeval tv1;
		tv1.tv_sec = 1;
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
			MY_PRINT("Recieve Data From peer Failed!");
			close(sock);
			continue;
    	}
		strcpy(buf2, buf);
	
	
		bzero(word, 30); wordlen=0; bufidx=0;
		while (buf[bufidx] != 0 && buf[bufidx] != ' ')
			word[wordlen++] = buf[bufidx++];
		int frompeerid=atoi(word);

		bzero(word, 30); wordlen=0; bufidx++;
		while (buf[bufidx] != 0 && buf[bufidx] != ' ')
			word[wordlen++] = buf[bufidx++];
    
		//MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"], peer.acitve=["<< peers[frompeerid].active <<"]");

		if (peers[frompeerid].active <= 0)peers[frompeerid].active  = 1;
		else peers[frompeerid].active++;
		if (!strcmp("startreq", word)){
			//startreq current_t
			//printf("server::global_T = %d\n", server::global_T);
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			//MY_PRINT("sock["<<sock <<"], req time=["<<str<<"], global time=["<< global_T <<"]");
		
			MY_PRINT("fromid["<< frompeerid <<"] word ["<<word <<"] ?= t ["<<global_T<<" ]");
			for (int tt=0; tt < atoi(word); tt++)
				fin [frompeerid][tt] = true;
			num_of_completed_peers =0;
			char nofin[MAXLINE ] = {0}, tmpi[10]={0};
			int no_i=0;
			for (int k=0; k<NUM_OF_PEERS; k++)
				if (fin[k][global_T] == true) num_of_completed_peers++;
				else{
					bzero (tmpi, 10); sprintf(tmpi, "%03d ", k);
					strcat(nofin + no_i, tmpi); no_i +=4;
				}

			MY_PRINT("server::rec : ["<<buf2<<"] from peerid["<< frompeerid <<"], its acitve=["<< peers[frompeerid].active 
					<<"], num_of_completed ["<< num_of_completed_peers <<"] num_of_active ["
					<< num_of_active_peers <<"] global_T ["<< global_T <<"] fresh["<< freshstates + 2<<"], no fin ["<< nofin<< "]");
			if (num_of_active_peers  && num_of_completed_peers >= num_of_active_peers ){ 
				//num_of_active_peers can only be decreased in once experiment.
				global_T++;
				if (global_T > NUM_OF_T)global_T = NUM_OF_T;
				MY_PRINT( "current t ["<< global_T <<"] =======================");
				//for (int k=0; k<NUM_OF_PEERS; k++)
				//	peers[k].fin = false;

				freshstates[1] = ' ';
				if (atoi(word) <= server::global_T )
					freshstates[0] = '1';
				else
					freshstates[0] = '0';
			
				send(sock, freshstates, strlen(freshstates)+1, 0);
				close(sock);

				if (server::global_T == NUM_OF_T && num_of_active_peers ==0 ){
					broadcast_close();
					node::To_listen = false;
					recordfail();
				}
				
			
			}
			else{
				freshstates[1] = ' ';
				if (atoi(word) <= server::global_T )
					freshstates[0] = '1';
				else
					freshstates[0] = '0';
			
				send(sock, freshstates, strlen(freshstates)+1, 0);
				close(sock);
			}

		}
		else if (!strcmp("finishreq", word)){
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			MY_PRINT("word ["<<word <<"] ?= t ["<<global_T<<" ]");
			for (int tt=0; tt <= atoi(word); tt++)
				fin [frompeerid][tt] = true;
			send(sock, "1", 2, 0);
			close(sock);


			num_of_completed_peers =0;
			char nofin[MAXLINE ] = {0}, tmpi[10]={0};
			int no_i=0;
			for (int k=0; k<NUM_OF_PEERS; k++)
				if ( fin[k][global_T] == true) num_of_completed_peers++;
				else{
					bzero (tmpi, 10); sprintf(tmpi, "%03d ", k);
					strcat(nofin + no_i, tmpi); no_i +=4;
				}
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]"
					<< " server current t ["<<  global_T <<"] upband["<< server::myoutput_bw 
					<< "] num_of_completed_peers[" << num_of_completed_peers
					<<"] active peers ["<< num_of_active_peers <<"] nofin["<<nofin <<"]");
			if (num_of_active_peers  && num_of_completed_peers >= num_of_active_peers ){ 
				//num_of_active_peers can only be decreased in once experiment.
				server::global_T++;
				if (global_T > NUM_OF_T)global_T = NUM_OF_T;
				MY_PRINT( "current t ["<< global_T <<"] ========================");
				//for (int k=0; k<NUM_OF_PEERS; k++)
				//	peers[k].fin = false;
				if (server::global_T == NUM_OF_T && num_of_active_peers ==0){
					broadcast_close();
					node::To_listen = false;
					recordfail();
				}
			
			}


		}
		else if (!strcmp("getsegs", word)){
			double reqbw;
			//alway return 1.
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]");
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			//MY_PRINT("parse["<< buf2<<"] 1 word  ["<< word <<"]");
			sscanf(word, "%lf", &reqbw);
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			//MY_PRINT("parse["<<buf2 <<"] 2 word  ["<< word <<"]");
			sscanf(word, "%lf", &recovery_time );
	
			send(sock, "1", 2, 0);
			close(sock);
			if (reqbw > server::myoutput_bw){ //fail
				failtime++;
				fail_bw[global_T][frompeerid] += reqbw - server::myoutput_bw;
				MY_PRINT("remain 0 failmeet server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]"
						<<" t["<< global_T<<"] frompeer["<< frompeerid<<"]  diff bw["
						<< reqbw - server::myoutput_bw<<"] failtime["<< failtime <<"] ");
			
				rec_t tmp_recovery(myoutput_bw,  recovery_time );
				recovery_bw += server::myoutput_bw ;
				//MY_PRINT("fail upband remain [0], reqbw["<< reqbw <<"] > myoutput_bw["<< myoutput_bw<<"], recovery_bw ["<< recovery_bw <<"]");
				server::myoutput_bw = 0;
	
				//usleep((int)(recovery_time * 1000000));
				//myoutput_bw += recovery_bw ;
				//MY_PRINT("recovery, after["<<recovery_time <<"]s, upband["<< myoutput_bw <<"] recovery_bw["<< recovery_bw <<"] ");
				//recovery_bw = 0;


				int stacksize = 20480; /*thread 堆栈设置为20K，stacksize以字节为单位。*/
				pthread_attr_t attr;
				pthread_t pid;
				pthread_attr_init(&attr); /*初始化线程属性*/
				pthread_attr_setstacksize(&attr, stacksize);
				int pret=pthread_create(&pid, &attr, recomvery_upband, &tmp_recovery );
				MY_PRINT("after fail invoke recov,pret=["<< pret<<"] recbw["<< myoutput_bw<<"] rectime["<< recovery_time <<"]");
				pthread_attr_destroy(&attr); /*不再使用线程属性，将其销毁*/

			}
			else{//success
				//update my upband, and inform other peers and server
				successtime++;
				rec_t tmp_recovery(reqbw ,  recovery_time );
				recovery_bw += reqbw;
				server::myoutput_bw -= reqbw ;
				MY_PRINT("remain "<< server::myoutput_bw<<" success server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]"
						<<" reqbw["<< reqbw <<"] recovery_bw ["<< recovery_bw <<"] suctime["<< successtime<<"]");
				
				//usleep((int)(recovery_time * 1000000));
				//myoutput_bw += recovery_bw ;
				//MY_PRINT("recovery, after["<<recovery_time <<"]s, upband["<< myoutput_bw <<"] recovery_bw["<< recovery_bw <<"] ");
				//recovery_bw = 0;
				int stacksize = 20480; /*thread 堆栈设置为20K，stacksize以字节为单位。*/
				pthread_attr_t attr;
				pthread_t pid;
				pthread_attr_init(&attr); /*初始化线程属性*/
				pthread_attr_setstacksize(&attr, stacksize);
				int pret=pthread_create(&pid, &attr, recomvery_upband, &tmp_recovery);
				MY_PRINT("after suc invoke recov, pret=["<<pret <<"] recbw["<< reqbw <<"] rectime["<< recovery_time <<"]");
				pthread_attr_destroy(&attr); /*不再使用线程属性，将其销毁*/
			}
		}
		else if (!strcmp("updatecache", word)){
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			//updatecache peerid seg_id1 seg_id2 ... : peerid has segs.
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]");
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
			//printf("updatecache, peerid=%d, segid=%d\n", peerid, segid);
			cache[peerid][segid] = true;

		}
		else if (!strcmp("updateupband", word)){
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]");
			bzero(word, 30); wordlen=0; bufidx++;
			while (buf[bufidx] != 0 && buf[bufidx] != ' ')
				word[wordlen++] = buf[bufidx++];
			double new_bw;
			//MY_PRINT("parse["<<buf2 <<"] 1 word  ["<< word <<"]");
			sscanf(word, "%lf", &new_bw);
			send(sock, "1", 2, 0);
			close(sock);
			peers[frompeerid].upband = new_bw;
		
		}

		else if (!strcmp("close", word)){
			send(sock, "1", 2, 0);
			close(sock);
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]");
			node::To_listen = false;
		}
		else if (!strcmp("test", word)){
			MY_PRINT("server::rec : ["<<buf2<<"] from ["<< frompeerid <<"]");
			sleep(5);
			send(sock, "1", 2, 0);
			MY_PRINT("server::send back: ["<< 1 <<"]");
		}
		else
			close(sock);


	//pthread_exit(NULL);



		//char client_ip[30] = {0};
		//strcpy(client_ip,  inet_ntoa(rec_clie_addrs[i_of_thread].sin_addr) );

		//pthread_create(&pthid[i_of_thread ], NULL, Parse_cmd , &accept_sock[i_of_thread]);
		//Parse_cmd (accept_sock[i_of_thread]);
		
		
		i_of_thread++;
		i_of_thread = i_of_thread % NUM_OF_PEERS;
	}

	
	return 1;
}

int server::serversend_cmd(node_p &p, char *cmd)
{

	int ret;
	
	//MY_PRINT("server send to ip["<< p.ip <<"], port["<< p.port <<"]");

	Set_DestIP(p.ip);
	Set_DestPORT(p.port);

	if (!Init_send()){
		MY_PRINT("fail send["<<cmd <<"] to peer["<<p.id <<"] ip["<<p.ip <<"] port["<<p.port <<"]");
		return 0;
	}
	if (/*cmd[3] != 'h' &&*/ cmd[3] != 'p') //heartbeat peerstates
		MY_PRINT("send["<<cmd <<"] to peer["<<p.id <<"] ip["<<p.ip <<"] port["<<p.port <<"]");
	ret = Send_cmd(cmd);
	
	Stop_cmd();
 
	return ret;
}

void server::broadcast_close(void)
{
	char tmpcmd[50];
	bzero(tmpcmd, 50);
	sprintf(tmpcmd, "-1 close");
	for (int i=0; i < NUM_OF_PEERS; i++){
		if (peers[i].active > 0)
			serversend_cmd(peers[i], tmpcmd);
	}

}

void server::recordfail(void)
{

	MY_PRINT("fail record*_*_*_*_*_*_*_*_*_*_*_*");
	for (int t=0; t<NUM_OF_T; t++) 
		for (int p=0; p<NUM_OF_PEERS; p++){
			if (fail_bw[t][p] > 0.001)
				MY_PRINT("fail t["<<t <<"] peer["<<p <<"] bw["<< fail_bw[t][p]<<"]"  );
		}

}

void* server::recomvery_upband(void* ptr)
{
	double recovery = ((rec_t*)ptr)->rec_bw;
	double rect = ((rec_t*)ptr)->rec_time;
	recoveryn++;
	
	MY_PRINT("remainbw "<< myoutput_bw <<" beforerec wait["<<rect <<"]s, recovery_bw["
			<< recovery <<"] recn ["<< recoveryn<<"]");
	usleep((int)(rect * 1000000));
	//myoutput_bw += recovery_bw ;
	myoutput_bw += recovery ;
	MY_PRINT("remain "<< myoutput_bw <<" recovery wait["<<rect <<"]s, recovery_bw["<< recovery <<"] ");
	recovery_bw = 0;
	pthread_detach(pthread_self());
	pthread_exit(NULL);

}


/*int server::Init_Listen()
{

	int ret = node::Init_Listen();
	if (ret == 0) return 0;
	

	pthread_t pid;
	pthread_create(&pid, NULL, heartbeat, NULL);


	return 1;
}*/

void* server::threadsend_heartbeat(void* ptr)
{
	int ret, pid = *(int*)ptr;


	if (peers[pid].active < -80){
		peers[pid].active += 5;
		pthread_exit(NULL);
	}

	char tmpcmd[30] = {0};
	sprintf(tmpcmd,   "-1 heartbeat");
	
	time_t start, end;
	start = time(NULL);

	ret = serversend_cmd(peers[pid], tmpcmd) ;
	end = time(NULL);
	
	if (end - start > 30) //time out is 40s
		peers[pid].active = -100;
	else if ( ret == 1 ){
		if (peers[pid].active <= 0) peers[pid].active = 1;
		else peers[pid].active++;
	}
	else{ //ret != 1
		peers[pid].active = 0;
	}
	
	pthread_exit(NULL);
}

void* server::heartbeat(void* ptr)
{

	char  broadcmd[MAXLINE ];
	while (server::To_listen){
		//pthread_t pthid[NUM_OF_PEERS];
		sleep(30);

		/*for (int i=0; i<NUM_OF_PEERS; i++){
			pthread_create(&pthid[i], NULL, threadsend_heartbeat, &i);
			sleep(1);
		}
		for (int i=0; i<NUM_OF_PEERS;i++)
			pthread_join(pthid[i],NULL);
			*/


		bzero(broadcmd, MAXLINE );
		sprintf(broadcmd, "-1 peerstates" );
		int len = strlen(broadcmd);
		int tmp_n = 0;
		//detect
		//MY_PRINT("server heartbeat 10s--------- ");
		for (int i=0; i < NUM_OF_PEERS; i++){
			broadcmd[len++] = ' ';
			if ( peers[i].active > 0){
				broadcmd[len++] = '1';
				tmp_n++; 
			}
			else{
				broadcmd[len++] = '0';
			}
		}
		num_of_active_peers = tmp_n;

		//broadcast result
		//MY_PRINT("broad cmd["<< broadcmd <<"]");
		for (int i=0; i < NUM_OF_PEERS; i++){
			if (peers[i].active > 0)
				serversend_cmd(peers[i], broadcmd );
		}

	}
}


void* server::refresh(void* ptr)
{
	
	int tmpn, len;
	len=0;
	for (int i=0; i<NUM_OF_PEERS-1; i++){
		freshstates[len++] = '1';
		freshstates[len++] = ' ';
	}
	freshstates[len] = 0;

	while (server::To_listen){
		sleep(10);
		bzero(freshstates, MAXLINE );
		len = 2;
		tmpn = NUM_OF_PEERS;
		for (int i=0; i < NUM_OF_PEERS; i++){
			peers[i].active--;
			if (peers[i].active <= 0) {
				tmpn--;
				freshstates[len++] = '0';
				freshstates[len++] = ' ';
			}
			else{
				freshstates[len++] = '1';
				freshstates[len++] = ' ';
			}
		}
		num_of_active_peers = tmpn;
		//freopen("active_node.cc", "w", stdout);
		//freopen("/dev/tty", "w", stdout);
	}
}


void* server::sendfail(void* ptr)
{
	int sock = *(int*)ptr;
	send(sock, "0", 2, 0);
}
void* server::sendsuccess(void* ptr)
{
	int sock = *(int*)ptr;
	MY_PRINT("send 1 to sock["<<sock <<"].");
	send(sock, "1", 2, 0);
}

void* server::Parse_cmd(void* psock)
{}
