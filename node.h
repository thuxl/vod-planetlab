#ifndef  NODE_H
#define  NODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "common.h"

class node_p {
public:
	int   active;
	double upband;
	char ip[20];
	int  port;
	int id;

	node_p(void):active(true), upband(0) {memset(ip,0,sizeof(ip));}
};



class provider{
public:
	int  peerid; //-1 is server, 0-n are peers.
	double  provided_bw;
	double  duration;
	provider():peerid(-1),provided_bw(0),duration(0){}
	provider(int p,double bw, double t):peerid(p),provided_bw(bw),duration(t){}
};


class node {
public:
	//rec
    static struct sockaddr_in     rec_serv_addr;
    static struct sockaddr_in     rec_clie_addr;
    static int                    rec_sock_id;
    static int                    rec_link_id;
	static int					   listen_control_port;
	static bool				   To_listen;
	static int					  myid;

	//send
	static struct sockaddr_in     send_serv_addr;
    static int                    send_sock_id;
	static int 				      send_dest_port ;
	static char 				  send_dest_ip[20];

	//for both of peers and server
	static bool				   cache[NUM_OF_PEERS][NUM_OF_SEGS];
	static node_p				   peers[NUM_OF_PEERS];
	static node_p				   servernode;
	static double 			   current_upbw;
	static double 			   being_used_duration;
	static time_t		start_t;
	
	static double   recovery_bw;
	static double   recovery_time;
	
	//rec
    node (void);
    ~node (void);
	void Set_ListenPort(int port);
	static int Init_Listen();
	virtual int Listen_cmd();
	virtual int Parse_cmd(int sock, char *ip);
	static void Stop_listen();

	//send
	static int Init_send();
	static void Set_DestIP(char *ip);
	static void Set_DestPORT(int port);
	static int Send_cmd(const char *cmd );
	static int Send_cmd(const char *cmd, char *ret );
	static int testSend_cmd(const char *cmd, char *ret );
	static void Stop_cmd();

	//for both of peers and server
	void set_all_ip(const char **peers_ip, const char *server_ip);
	void set_all_port(const int* peers_p, const int server_p);
	void set_all_outband(const double  *peers_outband , double server_outbw);
	void update_server_upband(double bw);
	void set_initcache(const bool initcache[][NUM_OF_SEGS]);
	
};

#endif
