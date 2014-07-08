#include "node.h"
#include <unistd.h>
#include <string.h>

#include <iostream>
using namespace std;

//#include "all_ip.cc"
struct sockaddr_in     node::rec_serv_addr;
struct sockaddr_in     node::rec_clie_addr;
int                    node::rec_sock_id;
int                    node::rec_link_id;
int					   node::listen_control_port;


bool				   node::To_listen = true;
bool				   node::cache[NUM_OF_PEERS][NUM_OF_SEGS] = {0};
node_p				   node::peers[NUM_OF_PEERS];
node_p				   node::servernode;
double 			   node::current_upbw = 0;
double 			   node::being_used_duration = 0;
time_t			   node::start_t;

struct sockaddr_in     node::send_serv_addr;
int                    node::send_sock_id;
int 				   node::send_dest_port ;
char 				   node::send_dest_ip[20];
double   			   node::recovery_bw   = 0;
double   			   node::recovery_time = 0;

int					  node::myid;

node::node (void)
{
	listen_control_port=TRANS_CONTROL_PORT0     ;
	send_dest_port=TRANS_CONTROL_PORT0     ;
	node::To_listen = true;
	memset(node::cache, 0, sizeof(node::cache));
	time(&start_t);
}
node::~node (void)
{
	node::To_listen = false;
}

//rec -------------------------------------
void node::Set_ListenPort(int port)
{
	listen_control_port = port;
}
int node::Init_Listen()
{

    if ((rec_sock_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    //if ((rec_sock_id = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Create socket failed");
        return 0;
    }
	
	//int yes=1;
	//if (setsockopt(rec_sock_id, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
	//	perror("setsockopt");
	//	return 0;
	//}
    /*fill the server sockaddr_in struct commented by guoqingbo*/
    memset(&rec_serv_addr, 0, sizeof(rec_serv_addr));
    rec_serv_addr.sin_family = AF_INET;
    rec_serv_addr.sin_port = htons(listen_control_port);
    rec_serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(rec_sock_id, (struct sockaddr *)&rec_serv_addr, sizeof(rec_serv_addr)) < 0 ) {
        perror("Bind socket failed");
        return 0;
    }

    if (-1 == listen(rec_sock_id, 10)) {
        MY_PRINT("Listen socket failed");
        return 0;
    }
	return 1;
}


int node::Listen_cmd()
{
    int                    clie_addr_len;
	int 				   pid;
	
	while (To_listen) { //a connection sends only one cmd.
	
		clie_addr_len = sizeof(rec_clie_addr);
    	rec_link_id = accept(rec_sock_id, (struct sockaddr *)&rec_clie_addr, (socklen_t*)&clie_addr_len);
    	if (rec_link_id < 0) {
			MY_PRINT("Accept socket failed:"<< rec_link_id );
        	return 0;
    	}

		char client_ip[30] = {0};
		strcpy(client_ip,  inet_ntoa(rec_clie_addr.sin_addr) );

		//pid = fork();
		//if (pid < 0) return 0;
		//if (pid == 0) //child process
		//{
			//close (rec_sock_id);
			Parse_cmd (rec_link_id, client_ip);
    		close (rec_link_id);
			//MY_PRINT("listen stop, start another listen!");
			//return 1;
		//}
		//else close (rec_link_id);
	}
	
	return 1;
}


int node::Parse_cmd(int sock, char* ip)
{
    char                   buf[MAXLINE];
    int                    recv_len=0;
    int                    write_leng;
    bzero(buf, MAXLINE);


	//no block rec
	struct timeval tv;
	tv.tv_sec = 10;
    tv.tv_usec = 0;
	fd_set  rset;
	FD_ZERO(&rset);
	FD_SET(sock, &rset);
	int nready = select(sock + 1, &rset, NULL, NULL, &tv);
	if (nready < 0) {
		perror("select err.");
        MY_PRINT("select err");
		return 0;
	} else if (nready == 0) {
        MY_PRINT("timeout ");
		return 0;
	}
	if (FD_ISSET(send_sock_id, &rset))
    	recv_len = recv(sock, buf, MAXLINE, 0);
        
	if(recv_len <= 0) {
		MY_PRINT("Recieve Data From Server Failed!");
		return 0;
    }
    MY_PRINT("received data:"<< buf);
	
	
	char *str;
	str=strtok(buf, " ");
	str=strtok(NULL, " ");
	if (!strcmp("getsegs", buf)){
		while (str!=NULL){
			str=strtok(NULL, " ");
		}
	}
	else if (!strcmp("updatecache", buf)){
		while (str!=NULL){
			str=strtok(NULL, " ");
		}
	}
	else if (!strcmp("close", buf)){
		node::To_listen = false;
	}
	else if (!strcmp("complete", buf)){
		while (str!=NULL){
			str=strtok(NULL, " ");
		}
	}





	return 1;
}

void node::Stop_listen()
{

	//node::To_listen = false;
    MY_PRINT("Stop_listen");
    close(rec_link_id);
    close(rec_sock_id); 

}


//send -------------------------------------
void node::Set_DestIP(char *ip)
{
    memset(send_dest_ip, 0, sizeof(send_dest_ip));
	strcpy(send_dest_ip, ip);
}
void node::Set_DestPORT(int port)
{
	send_dest_port = port;
}

int node::Init_send()
{
    int                    i_ret;
    
    /* create the socket commented by guoqingbo*/
    if ((send_sock_id = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        MY_PRINT("Sender Create socket failed");
        return 0;
    }
    
    memset(&send_serv_addr, 0, sizeof(send_serv_addr));
    send_serv_addr.sin_family = AF_INET;
    send_serv_addr.sin_port = htons(send_dest_port);
    inet_pton(AF_INET, send_dest_ip, &send_serv_addr.sin_addr);
   
    /* connect the server commented by guoqingbo*/
    i_ret = connect(send_sock_id, (struct sockaddr *)&send_serv_addr, sizeof(struct sockaddr));
    if (i_ret < 0) {
       perror("Connect socket failed");
       return 0;
    }

	return 1;
}


int node::Send_cmd(const char *cmd)
{
    
    char                   buf[MAXLINE];
    int                    cmd_len;
    int                    len;
    /* transported the file commented by guoqingbo*/
    bzero(buf, MAXLINE);
	strcpy(buf, cmd);
	cmd_len = strlen(cmd) + 1;

	//MY_PRINT("node send ["<< cmd <<"]");
	len = send(send_sock_id, buf, cmd_len, 0);
    if ( len < 0 ) {
        MY_PRINT("Send cmd failed.");
        return 0 ;
    }
    bzero(buf, MAXLINE);
	len=0;

	//no block rec
	struct timeval tv;
	tv.tv_sec = 10;
    tv.tv_usec = 0;
	fd_set  rset;
	FD_ZERO(&rset);
	FD_SET(send_sock_id, &rset);
	int nready = select(send_sock_id + 1, &rset, NULL, NULL, &tv);
	if (nready < 0) {
		perror("select err.");
        MY_PRINT("select err");
		return 0;

	} else if (nready == 0) {
        MY_PRINT("timeout ");
		return 0;
	}



	if (FD_ISSET(send_sock_id, &rset))
		len = recv (send_sock_id, buf, MAXLINE, 0); 
	//MY_PRINT("feedback len["<<len <<"], data["<<buf <<"]");
	if (len <= 0) return 0;
	if (len > 0) 
		if (cmd[3] != 'h' && cmd[3] != 'p') //heartbeat peerstates from server
			MY_PRINT("node rec feedback: ["<<buf<<"]");
	char ret[2];  ret[0] = buf[0]; ret[1] = 0;
	return atoi(ret);

}

int node::Send_cmd(const char *cmd, char *ret )
{
    
    char                   buf[MAXLINE];
    int                    cmd_len;
    int                    len;
    /* transported the file commented by guoqingbo*/
    bzero(buf, MAXLINE);
	strcpy(buf, cmd);
	cmd_len = strlen(cmd) + 1;

	//MY_PRINT("node send ["<<cmd <<"]");
	len = send(send_sock_id, buf, cmd_len, 0);
    if ( len < 0 ) {
        MY_PRINT("Send cmd failed.");
        return 0 ;
    }
    bzero(buf, MAXLINE);
	len=0;

	//no block rec
	struct timeval tv;
	tv.tv_sec = 10;
    tv.tv_usec = 0;
	fd_set  rset;
	FD_ZERO(&rset);
	FD_SET(send_sock_id, &rset);
	int nready = select(send_sock_id + 1, &rset, NULL, NULL, &tv);
	if (nready < 0) {
		perror("select err.");
        MY_PRINT("select err");
		return 0;

	} else if (nready == 0) {
        MY_PRINT("timeout ");
		return 0;
	}



	if (FD_ISSET(send_sock_id, &rset))
		len = recv (send_sock_id, buf, MAXLINE, 0); 
	if (len <= 0) return 0;
	if (len > 0) 
		if (cmd[3] != 'h' && cmd[3] != 'p') //heartbeat peerstates from server
			MY_PRINT("node rec feedback: ["<<buf<<"]");
	char str[2];
	str[0] = buf[0]; str[1] = 0;
	int ret_i = atoi(str);
	strcpy(ret, buf+2);
	return ret_i;

}

int node::testSend_cmd(const char *cmd, char *ret )
{
    
    char                   buf[MAXLINE];
    int                    cmd_len;
    int                    len;
    /* transported the file commented by guoqingbo*/
    bzero(buf, MAXLINE);
	strcpy(buf, cmd);
	cmd_len = strlen(cmd) + 1;

	//MY_PRINT("node send ["<<cmd <<"]");
	len = send(send_sock_id, buf, cmd_len, 0);
    if ( len < 0 ) {
        MY_PRINT("Send cmd failed.");
        return 0 ;
    }
    bzero(buf, MAXLINE);
	len=0;

	
	//no block rec
	struct timeval tv;
	tv.tv_sec = 10;
    tv.tv_usec = 0;
	fd_set  rset;
	FD_ZERO(&rset);
	FD_SET(send_sock_id, &rset);
	int nready = select(send_sock_id + 1, &rset, NULL, NULL, &tv);
	if (nready < 0) {
		perror("select err.");
        MY_PRINT("select err");
		return 0;

	} else if (nready == 0) {
        MY_PRINT("timeout ");
		return 0;
	}



	if (FD_ISSET(send_sock_id, &rset)){
		MY_PRINT("there are some data to read. ");
		len = recv (send_sock_id, buf, MAXLINE, 0); 
	}
	if (len <= 0) return 0;
	if (len > 0) 
		if (cmd[3] != 'h' && cmd[3] != 'p') //heartbeat peerstates from server
			MY_PRINT("node rec feedback: ["<<buf<<"] len["<<len <<"]");
	char str[2];
	str[0] = buf[0]; str[1] = 0;
	int ret_i = atoi(str);
	strcpy(ret, buf+2);
	return ret_i;

}

void node::Stop_cmd()
{
    close(send_sock_id);
    //printf("Send Finish\n");
}


void node::set_all_ip(const char **peers_ip, const char *server_ip)
{
	for (int i=0; i<NUM_OF_PEERS; i++){
		strcpy(peers[i].ip, peers_ip[i]);
		peers[i].id = i;
		peers[i].active = 1;
	}
		
	strcpy(servernode.ip, server_ip);
	servernode.active = 1;
	servernode.id = -1;

}

void node::set_all_port(const int* peers_p, const int server_p)
{
	for (int i=0; i<NUM_OF_PEERS; i++)
		peers[i].port  =  peers_p[i];
		
	servernode.port  =  server_p;
}




void node::set_all_outband(const double  *peers_outband, double server_outbw)
{
	for (int i=0; i<NUM_OF_PEERS; i++)
		peers[i].upband = peers_outband[i]; 
	servernode.upband = server_outbw;
}

void node::update_server_upband(double bw)
{
	servernode.upband = bw;
}


void node::set_initcache(const bool initcache[][NUM_OF_SEGS])
{
	for (int i=0; i<NUM_OF_PEERS; i++)
		for (int j=0; j<NUM_OF_SEGS; j++)
			cache[i][j] = initcache[i][j];
}


