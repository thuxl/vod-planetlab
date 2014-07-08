#include "peer.h"
#include "all_ip.cc"
#include "configure.cc"

#include <iostream>
using namespace std;


#ifdef PEER_ID

#else
#define PEER_ID   0
error;
#endif

int main()
{
	peer p;
	//char addr[20] ;
	//
	
	p.set_peerid(PEER_ID);
	p.set_all_ip(peers_ip, server_ip);
	p.set_all_port(peers_port, server_port );
	p.Set_ListenPort(peers_port[PEER_ID]);
	
	p.set_outband(peer_outband[PEER_ID], peer_outband);
	p.set_all_outband(peer_outband, server_outbw);
	p.set_reqs(peer_reqid[PEER_ID], peer_reqbw[PEER_ID]);
	p.set_initcache(initcache);
	
	
	//int pid = fork();
	//if (pid < 0) return 0;
	//if (pid == 0) //child process

	pthread_t pid;
	pthread_create(&pid, NULL, p.listen_thread, NULL);
		
	p.run();
	//p.testrun();

	MY_PRINT("peer ["<<PEER_ID <<"] run over.");

	return 1;

}
