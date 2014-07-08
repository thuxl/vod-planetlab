#include "server.h"
#include "all_ip.cc"
//#include "all_hostname.cc"
#include "configure.cc"

#include <iostream>
using namespace std;

int main()
{

	server r;
	
	r.set_serverid(-1);
	r.set_all_ip(peers_ip, server_ip);
	r.set_server_upband(server_outbw);
	r.set_all_outband(peer_outband, server_outbw);
	r.set_all_port(peers_port, server_port );
	r.Set_ListenPort(server_port);

	pthread_t pid1, pid2;
	//pthread_create(&pid1, NULL, r.heartbeat, NULL);
	pthread_create(&pid2, NULL, r.refresh, NULL);

	while (r.To_listen == true) {
		MY_PRINT("remain "<< server_outbw<<"t [0] =======================");
		if(!r.Init_Listen())
			return 0;
		if (!r.Listen_cmd())
			return 0;
		r.Stop_listen();
	}


	MY_PRINT("server normal down. ");

	return 1;

}
