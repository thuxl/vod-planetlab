#ifndef  SERVER_H
#define  SERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "common.h"
#include "node.h"

/*
 * cmd intro.
 * get seg_id1 seg_id2 ... : i need segs.
 * update peerid seg_id1 seg_id2 ... : peerid has segs.
 */

class rec_t{
public:
	double rec_bw;
	double rec_time;

	rec_t(){rec_bw=0; rec_time=0;}
	rec_t(double bw, double t){rec_bw=bw; rec_time=t;}
};
class server: public node {
public:
	static int      num_of_completed_peers;
	static int 		global_T;
	static double   remain_upbw;
	static double   myoutput_bw;
	static double   fail_bw[NUM_OF_T+1][NUM_OF_PEERS];
	static int      num_of_active_peers;
	static char     freshstates[MAXLINE];
	static pthread_mutex_t mutex;
	static pthread_spinlock_t spinlock;
	static bool     fin[NUM_OF_PEERS][NUM_OF_T+1];
	static int      failtime, successtime, recoveryn;

    server (void);
	
	void set_server_upband(double bw); //in kbps
	void set_serverid(int sid);
	static void* Parse_cmd(void* sock);

	static void broadcast_close(void);
	static int serversend_cmd(node_p &p , char *cmd);
	static void recordfail(void);


	static void* recomvery_upband(void* ptr);
	static void* sendfail(void* ptr);
	static void* sendsuccess(void* ptr);
	
	int Listen_cmd();
	//int Init_Listen();
	static void* heartbeat(void* ptr);
	static void* threadsend_heartbeat(void* ptr);
	static void* refresh(void* ptr);

};

#endif
