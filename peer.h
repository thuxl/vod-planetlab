#ifndef  PEER_H
#define  PEER_H

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

#include <vector>
#include <iostream>
using namespace std;

class peer: public node {
public:
	static   int current_T;
	static int 	 mypeerid;
	static double   myoutput_bw;
	double   peer_output_bw[NUM_OF_PEERS];
	int      req_segid[NUM_OF_T];
	double   req_segbw[NUM_OF_T];
	vector <provider> provider_list;


    peer (void);
	void set_outband(const double mybw, const double* peersbw);
	void set_reqs(const int *reqids, const double *bw);
	void set_peerid(int id);
	int run();
	int testrun();

	static int peersend_cmd(node_p &p , char *cmd);
	int peersend_cmd(node_p &p , char *cmd, char *ret_str);
	void broadcast_cache(int peerid, int segid);
	static void* Parse_cmd(void* psock );
	int send_reqs(int segid);
	
	static void* broadcast_myupband(void* ptr);
	static void* recovery_upband(void* ptr);
	static void* send_fail(void* sock);

	static void* listen_thread(void* ptr);
	
	static int peer_Listen_cmd();
};

#endif
