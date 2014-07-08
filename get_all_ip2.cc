#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
 
//以下头文件是为了使样例程序正常运行
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "common.h"
int main()
{
	const int num=307-75; //NUM_OF_PEERS;
	const char* hostname[num] = {
	"pl1.6test.edu.cn",
	"pl2.6test.edu.cn",
	//"planetlab2.csee.usf.edu",
	"planetlab2.csg.uzh.ch",
	"pl1.tailab.eu",
	"planetlab2.ionio.gr",
	//"ple01.fc.univie.ac.at", //timeout
	"planetlab1.csuohio.edu",
	"pl-node-1.csl.sri.com",
	//"onelab3.info.ucl.ac.be", // Name or service not known
	"planetlab1.xeno.cl.cam.ac.uk",
	//"peeramide.irisa.fr", //timeout
	"planetlab01.tkn.tu-berlin.de",
	"planetlab-2.cs.auckland.ac.nz",
	//"planetlab-2.sysu.edu.cn", //timeout
	"planetlab1.acis.ufl.edu",
	"pl2.tailab.eu",
	//"csplanetlab3.kaist.ac.kr", //permission deniaed
	"planetlab4.wail.wisc.edu",
	//"planetlab-13.e5.ijs.si", //timeout
	"ple2.tu.koszalin.pl",
	"planetlab-3.cs.ucy.ac.cy",
	"ricepl-5.cs.rice.edu",
	//"planetlab1.sics.se", //timeout
	"planet-lab4.uba.ar",
	"planetlab2.acis.ufl.edu",
	"aguila2.lsi.upc.edu",
	//"planck250ple.test.iminds.be", // No route to host
	"planetlab1.cs.uml.edu",
	"planetlab3.di.unito.it",
	//"planetlab2.buaa.edu.cn", //timeout
	"planetlab-2.scie.uestc.edu.cn",
	"aguila1.lsi.upc.edu",
	"planetlab6.csee.usf.edu",
	//"planetlab1.hust.edu.cn", //time out
	"planetlab-2.usask.ca",
	//"planet-lab1.cs.ucr.edu", // Name or service not known
	"planetlab1.cs.pitt.edu",
	//"planet-lab2.ufabc.edu.br", //Permission denied
	"kc-sce-plab2.umkc.edu",
	"planet-plc-3.mpi-sws.org",
	"planetlab1.inf.ethz.ch",
	"planetlab2.cs.uiuc.edu",
	"planetlab1.cs.uiuc.edu",
	"planetlab1.eecs.umich.edu",
	"planetlab2.koganei.itrc.net",
	//"planetlab-1.scie.uestc.edu.cn", //time out
	"planetlab1.koganei.itrc.net",
	"ricepl-2.cs.rice.edu",
	"planetlab2.informatik.uni-erlangen.de",
	"kc-sce-plab1.umkc.edu",
	"planetlab2.comp.nus.edu.sg",
	//"planetlab2.bgu.ac.il", //no space left
	"planetlab2.postel.org",
	"planetlab3.cesnet.cz",
	"planetlab1.exp-math.uni-essen.de",
	"planetlab1.dojima.wide.ad.jp",
	//"csplanetlab4.kaist.ac.kr", //Permission denied
	"planetlab2.cis.upenn.edu",
	"ple1.zcu.cz",
	"planetlab1.netlab.uky.edu",
	"75-130-96-12.static.oxfr.ma.charter.com",
	//"planet1.l3s.uni-hannover.de", //Connection timed out
	"planetlab3.georgetown.edu",
	"planetlab1.postel.org",
	"pl3.cs.unm.edu",
	"pl1.prakinf.tu-ilmenau.de",
	"pli1-pa-2.hpl.hp.com",
	//"pl2.prakinf.tu-ilmenau.de", //Connection timed out
	"pli1-pa-1.hpl.hp.com",
	"planet-lab2.uba.ar",
	"planetlab3.net.in.tum.de",
	"planetlab1.net.in.tum.de",
	"pli1-pa-3.hpl.hp.com",
	"pl1.cs.unm.edu",
	"planetlab1.pop-pa.rnp.br",
	//"planetlab2.dit.upm.es", //'vserver ... suexec' is supported for running vservers only; aborting..
	//"plab-2.diegm.uniud.it", //Permission denied
	//"planetvs2.informatik.uni-stuttgart.de", //No route to host
	"node2pl.planet-lab.telecom-lille1.eu",
	"planetlab2.csie.nuk.edu.tw",
	//"planetlab2.upm.ro", //Connection timed out
	//"planetlab1.tmit.bme.hu", //key changed.
	"plab-1.diegm.uniud.it",
	//"planetlab-2.fhi-fokus.de", //Connection timed out
	"peeramidion.irisa.fr",
	"planetlab-um00.di.uminho.pt",
	//"planetlab2.tau.ac.il", //Connection refused
	//"dannan.disy.inf.uni-konstanz.de", //Permission denied 
	"host2.planetlab.informatik.tu-darmstadt.de",
	//"147-179.surfsnel.dsl.internl.net", // Connection timed out
	//"plab4.ple.silweb.pl", // Name or service not known
	//"planetlab02.dis.unina.it", //Permission denied
	//"planetlab-1.imag.fr", //Connection timed out
	"node2.planetlab.mathcs.emory.edu",
	"planetlab1.informatik.uni-goettingen.de",
	//"planet2.l3s.uni-hannover.de", // Connection timed out
	"planetlab-1.sjtu.edu.cn",
	"pl4.cs.unm.edu",
	//"planetlab2.fct.ualg.pt", //'vserver ... suexec' is supported for running vservers only; aborting...
	"planetlab1.ionio.gr",
	//"planetlab1lannion.elibel.tm.fr", // Connection timed out
	"planetlab2.science.unitn.it",
	"uoepl1.essex.ac.uk",
	"planetlab2.unineuchatel.ch",
	"planetlab1.ifi.uio.no",
	"planetlab2.ifi.uio.no",
	"planetlab2.eurecom.fr",
	"planetlab4.hiit.fi",
	//"planetlab4.cs.st-andrews.ac.uk", // Connection timed out
	//"planetlab2.tmit.bme.hu", //Permission denied
	//"planetlab-1.man.poznan.pl", //Connection timed out
	//"planetlab02.cs.tcd.ie",//Connection timed out
	"planetlab2.mta.ac.il",
	//"planetlab1.cyfronet.pl", //Connection timed out
	//"planetlab02.cnds.unibe.ch", //Connection timed out
	"planet1.unipr.it",
	"pandora.we.po.opole.pl",
	"planck227ple.test.ibbt.be",
	"planetlab3.comp.nus.edu.sg",
	"planet2.servers.ua.pt",
	//"dschinni.planetlab.extranet.uni-passau.de", //Permission denied
	"planet-lab-node2.netgroup.uniroma2.it",
	//"inriarennes2.irisa.fr", // Name or service not known
	"planet1.servers.ua.pt",
	"host1.planetlab.informatik.tu-darmstadt.de",
	"planetlab4.williams.edu",
	"iraplab1.iralab.uni-karlsruhe.de",
	"planetlab3.hiit.fi",
	//"146-179.surfsnel.dsl.internl.net", //Connection timed out
	"evghu4.colbud.hu",
	//"host149-82-static.93-94-b.business.telecomitalia.it", //Connection timed out
	"evghu5.colbud.hu",
	"evghu6.colbud.hu",
	"evghu7.colbud.hu",
	"planetlab-1.research.netlab.hut.fi",
	//"planetlab04.cnds.unibe.ch", //Connection timed out
	"planetlab2.s3.kth.se",
	//"planetlab-1.iscte.pt", //Connection timed out
	"planetlab2.ci.pwr.wroc.pl",
	//"planetlab01.cs.tcd.ie", //Connection timed out
	"planet2.cs.huji.ac.il",
	"planetlab2.diku.dk",
	"planetlab-4.imperial.ac.uk",
	"planetlab2.cs.uit.no",
	"planetlab-4.cs.ucy.ac.cy",
	"planetlab-12.e5.ijs.si",
	"planetlab1.fct.ualg.pt",
	//"planetlab1.dit.upm.es", //Permission denied
	"iraplab2.iralab.uni-karlsruhe.de",
	//"planetlabeu-2.tssg.org", //Permission denied
	"planet2.unipr.it",
	"planetlab2.cs.uoregon.edu",
	"plnode-04.gpolab.bbn.com",
	"node1.planetlab.mathcs.emory.edu",
	"planetlab2.mini.pw.edu.pl",
	"planetlab1.c3sl.ufpr.br",
	"planet1.pnl.nitech.ac.jp",
	"planetlab2.netlab.uky.edu",
	"planetlab-1.cs.auckland.ac.nz",
	"pli1-pa-5.hpl.hp.com",
	"planetlab1.cesnet.cz",
	"planetlab0.otemachi.wide.ad.jp",
	"pl01.comp.polyu.edu.hk",
	"pli1-pa-4.hpl.hp.com",
	//"planetlab3.arizona-gigapop.net", //Name or service not known
	//"planetlab2.arizona-gigapop.net", //Name or service not known
	"planetlab1.cs.okstate.edu",
	//"planetlab1.cs.otago.ac.nz", // Name or service not known
	"planetlab1.csie.nuk.edu.tw",
	"planet4.cc.gt.atl.ga.us",
	"planetlab-1.cs.uic.edu",
	"planetlab02.cs.washington.edu",
	"planet-lab2.cs.ucr.edu",
	"planetlab1.unl.edu",
	"planetlab2.cs.columbia.edu",
	"planetlab2.cs.pitt.edu",
	"planetlab3.inf.ethz.ch",
	"planetlab2.eecs.wsu.edu",
	"pl2.ucs.indiana.edu",
	//"pli1-pa-6.hpl.hp.com", //Permission denied
	"planetlab-1.calpoly-netlab.net",
	"planetlab3.cnds.jhu.edu",
	"planetlab1.just.edu.jo",
	"planetlab2.cs.vu.nl",
	"planet-plc-2.mpi-sws.org",
	//"planet02.hhi.fraunhofer.de", //time out
	"planetlab1.otemachi.wide.ad.jp",
	"planetlab1.unineuchatel.ch",
	//"planetlab2.montefiore.ulg.ac.be", //ssh_exchange_identification: Connection closed by remote host
	//"planetlab1.fri.uni-lj.si", //Permission denied 
	//"planet2.inf.tu-dresden.de", //time out
	"evghu1.colbud.hu",
	"plab4.eece.ksu.edu",
	"planetlab2.cs.colorado.edu",
	//"planetlab-node-01.ucd.ie", //time out
	"planetlab2.ics.forth.gr",
	//"planetlab1.wiwi.hu-berlin.de", //time out
	"planet1.colbud.hu",
	"planetlab1.informatik.uni-wuerzburg.de",
	"rochefort.infonet.fundp.ac.be",
	"onelab1.info.ucl.ac.be",
	"planetlab1.polito.it",
	"gschembra4.diit.unict.it",
	"planetlab1.mta.ac.il",
	"planetlab-2.tagus.ist.utl.pt",
	//"ple1.ait.ac.th", //timeout
	"planetlab3.bupt.edu.cn",
	"planetlab1.ecs.vuw.ac.nz",
	//"planetlab2-santiago.lan.redclara.net", //Permission denied
	"righthand.eecs.harvard.edu",
	"planetlab01.alucloud.com",
	//"planetlab01.ethz.ch", //time out
	"evghu2.colbud.hu",
	"evghu10.colbud.hu",
	//"planetlab1.cs.uoi.gr", //too slow
	"pl1.sos.info.hiroshima-cu.ac.jp",
	"dplanet2.uoc.edu",
	"planetlab2.ecs.vuw.ac.nz",
	"planetlab1.extern.kuleuven.be",
	"planetlab2.extern.kuleuven.be",
	"planetlab3.mini.pw.edu.pl",
	"planetlab-1.cse.ohio-state.edu",
	"planet-lab1.uba.ar",
	"planetlab2.cs.otago.ac.nz",
	//"pl1.ccsrfi.net", //time out
	"pl2.ccsrfi.net",
	"planetlab2.clemson.edu",
	"planetlab1.clemson.edu",
	"planetlab2.cs.okstate.edu",
	"planetlab2.pop-pa.rnp.br",
	//"planet1.dsp.ac.cn", //too slow
	"planetlab1.cis.upenn.edu",
	"planetlab-1.ssvl.kth.se",
	"pl2.eng.monash.edu.au",
	"planetlab1.cqupt.edu.cn",
	"pl2.cs.montana.edu",
	"planetlab1.cnis.nyit.edu",
	"pl2.sos.info.hiroshima-cu.ac.jp",
	"planetlab1.uta.edu",
	"planetlab1.utt.fr",
	"utet.ii.uam.es",
	"planetlab2.upc.es",
	"dplanet1.uoc.edu",
	//"planetlab-2.imag.fr", //time out
	"lim-planetlab-2.univ-reunion.fr",
	//"planetlab-1.imperial.ac.uk", //time out
	//"planet2.dsp.ac.cn", //too slow
	"planetlab02.alucloud.com",
	"planetlab2.cs.uml.edu",
	//"onelab1.warsaw.rd.tp.pl", // time out
	"pub1-s.ane.cmc.osaka-u.ac.jp",
	"planetlab2.cs.ubc.ca",
	"planetlab3.wail.wisc.edu",
	"pub2-s.ane.cmc.osaka-u.ac.jp",
	"planetlab2.utdallas.edu",
	//"jupiter.planetlab.carleton.ca", //timeout
	//"planetlab-2.cse.ohio-state.edu", //timeout
	//"planetlab1.jcp-consult.net", //time out
	"lefthand.eecs.harvard.edu",
	"planetlab2.jcp-consult.net",
	"planetlab-2.cs.colostate.edu",
	"plab2.nec-labs.com",
	//"planetlab1.di.fct.unl.pt", //Permission denied
	//"aladdin.planetlab.extranet.uni-passau.de",//Permission denied
	"planetlab-2.sjtu.edu.cn",
	"roti.mimuw.edu.pl",
	//"planetlab1.csee.usf.edu",  //Permission denied
	//"marie.iet.unipi.it",   // Connection timed out
	//"planetlab2.fri.uni-lj.si",  //Connection timed out
	"planet3.cs.ucsb.edu",
	"pl2.rcc.uottawa.ca",
	"pl2.uni-rostock.de",
	"planetlab-01.vt.nodes.planet-lab.org",
	"planetlab1.cs.du.edu",
	"ricepl-1.cs.rice.edu",
	"planetlab1.fit.vutbr.cz",

	//"pl2.zju.edu.cn", //permission denied.
	"vicky.planetlab.ntua.gr",
	//"planetlab2.cs.uoi.gr", //timeout
	"planetlab1.arizona-gigapop.net",
	//"planetlab2.sics.se", //timeout
	//"planetlab2-saopaulo.lan.redclara.net",
	//"openlab01.pl.sophia.inria.fr", //timeout
	"pl1.cs.montana.edu",
	//"onelab2.warsaw.rd.tp.pl", //timeout
	"dfn-ple1.x-win.dfn.de",
	"anateus.ipv6.lip6.fr",
	"ple4.ipv6.lip6.fr",
	"ple3.ipv6.lip6.fr",
	"ple2.ipv6.lip6.fr",
	"ple5.ipv6.lip6.fr",
	"ple6.ipv6.lip6.fr",
	"plewifi.ipv6.lip6.fr",

	"planetlab1.cs.vu.nl",
	"pllx2.parc.xerox.com",
	"saturn.planetlab.carleton.ca",
	"planetlab2.jhu.edu",
	"plnode-03.gpolab.bbn.com",
	"venus.silicon-valley.ru",
	"vn4.cse.wustl.edu",
	"netapp6.cs.kookmin.ac.kr",
	"planetlab3.cs.columbia.edu",
	"planet2.ku.edu.tr",
	"planetlab-02.bu.edu",
	"planetlab-3.cmcl.cs.cmu.edu",
	"pl1.eng.monash.edu.au"

	};

	struct hostent *nlp_host;
	//for (int i=0; i<num; i++){
	int start_i = 0;
	int active_i = 0;
	int i = 0;
	int intra_i =0 ;
	int diff_i = 0;
	while (i < num && active_i < NUM_OF_PEERS) {
		// //解析域名，如果是IP则不用解析，如果出错，显示错误信息
		if ( (nlp_host = gethostbyname(hostname[i]) )  == 0 ){
			//printf("\n");
			freopen("/dev/tty", "w", stdout);
			printf("%d %s ---fail \n", i, hostname[i]);
			if (i==start_i) start_i++;
			i++;
			continue;
		}
		char ip[30] = {0};
		strcpy(ip, inet_ntoa(*((struct in_addr *) nlp_host->h_addr)));


		if (i==start_i){
			//================================  run
			freopen("run", "w", stdout);
			printf("#!/bin/bash\n\n");
			for (int pi=0; pi<PEERS_ON_NODE; pi++ )
				printf("./p_peer%03d & ", pi);
			printf("\n");

			//================================  iplist.txt
			freopen("iplist.txt", "w", stdout);
			printf("%s\n",ip);
			printf("#%s\n", hostname[i]);
			//================================  testnodes
			freopen("testnodes", "w", stdout);
			printf("#!/bin/bash\n");
			printf("ips=(");
			printf("%s ", hostname[i]);


			//================================  upload
			freopen("upload", "w", stdout);
			printf("#!/bin/bash\n");
			//scp -i id_rsa p_peer000 tsinghua_leixu@pl1.6test.edu.cn:~/p_peer000
			printf("#./vxargs-latest.py -a iplist.txt -o ./tmpresult/ -t 60  ssh -l tsinghua_leixu -i id_rsa {} \"killall -9 p_peer000\"\n");
			printf("ips=(");
			printf("%s ", hostname[i]);



	
		}
		else{
			int nodes = (NUM_OF_PEERS - 1)/PEERS_ON_NODE + 1;
			
			//================================  iplist.txt
			freopen("iplist.txt", "a", stdout);
			printf("%s\n",ip);
			printf("#%s\n", hostname[i]);
			//================================  testnodes
			freopen("testnodes", "a", stdout);
			printf("%s ", hostname[i]);
			if (diff_i ==  nodes - 1) {
				printf(");\n\nfor((i=0;i<%d;i++));do\n", nodes);
				printf("{\n\t echo \"[$i] ${ips[$i]}\"; ssh -l tsinghua_leixu -i id_rsa ${ips[$i]} \"hostname;uptime\"\n");
				printf("}&\ndone\nwait\n");
			}
			//printf("echo \"[$i] %s\"; i=`echo \"$i+1\" |bc`;", hostname[i]);
			//printf("ssh -l tsinghua_leixu -i id_rsa %s \"uptime\"\n",hostname[i] );
			
			//================================  upload
			freopen("upload", "a", stdout);
			printf("%s ", hostname[i]);
			if (diff_i == nodes - 1) {
				printf(");\n\nk=0\nfinal=\n");

				printf("for((i=0;i<%d;i++));do\n", nodes);
				printf("{\n\tssh -l tsinghua_leixu -i id_rsa ${ips[$i]} ");
				printf("\"rm p_peer* run node.* peer.*  peermain_000.cc server.* servermain.cc all_ip.cc configure.cc common.h makefile  \"\n");
				printf("}&\ndone\nwait\n");

				printf("for((i=0;i<%d;i++));do\n{\n", nodes );
				/*printf("\tfor((j=0;j<%d;j++));do\n\t{\n", PEERS_ON_NODE );
				printf("\t\tif [[ $k -ge %d ]]\n", NUM_OF_PEERS);
				printf("\t\tthen\n\t\t\tbreak\n\t\telse\n");
				printf("\t\t\tk=`echo \"$i*%d+$j\"|bc`\n", PEERS_ON_NODE );
				printf("\t\t\tfile1=`printf \"p_peers/p_peer%%03d \" $k`\n");
				printf("\t\t\tfile2=`printf \"p_peer%%03d\" $j`\n");
				printf("\t\t\techo \"[$k][$i] scp -i id_rsa $file1 tsinghua_leixu@${ips[$i]}:~/$file2\"\n");
				printf("\t\t\tscp -i id_rsa $file1 tsinghua_leixu@${ips[$i]}:~/$file2\n\t\tfi\n");
				printf("\t}&\n\tdone\n");
				printf("\tscp -i id_rsa run tsinghua_leixu@${ips[$i]}:~/\n");*/
				
				printf("\tscp -i id_rsa run node.* peer.*  peermain_000.cc server.*");
				printf(" servermain.cc all_ip.cc configure.cc common.h tsinghua_leixu@${ips[$i]}:~/\n");
				printf("\tscp -i id_rsa p_peers/peermakefile$i tsinghua_leixu@${ips[$i]}:~/makefile\n");

				printf("}&\ndone\nwait\n");


			}
	
		}





		for (intra_i =0 ;intra_i < PEERS_ON_NODE && active_i < NUM_OF_PEERS; intra_i++, active_i++ )
		{

	

		if (i == start_i&& active_i == 0) {
			//================================  all_hostname.cc
			freopen("all_hostname.cc", "w", stdout);
			printf("const char* 		   peers_hostname[NUM_OF_PEERS] =   { ");
			printf("\"%s\" /*%d*/\n", hostname[i], active_i);
			//================================  all_ip.cc
			freopen("all_ip.cc", "w", stdout);
			printf("const char* 		   server_ip  = \"166.111.70.19\";\n");
			//printf("const char* 		   server_ip  = \"131.247.2.242\";\n"); //"planetlab2.csee.usf.edu",
			printf("const int 		   	   server_port = TRANS_CONTROL_PORT0;\n");
			printf("const int 		   	   peers_port[NUM_OF_PEERS] = {\nTRANS_CONTROL_PORT0");
			
			for (int j=1, in_j = 1; j<NUM_OF_PEERS; j++, in_j++){
				printf(", TRANS_CONTROL_PORT%d", in_j);
				if (in_j == PEERS_ON_NODE-1)in_j = -1;
				if (j%6 == 0)  printf("\n");
			}
			printf(" };\n");
			printf("const char* 		   peers_ip[NUM_OF_PEERS] =   { ");
			printf("\"%s\" /*%d*/\n", inet_ntoa(*((struct in_addr *) nlp_host->h_addr)), active_i);
			
		
		}
		else{
			//================================  all_hostname.cc
			freopen("all_hostname.cc", "a", stdout);
			printf(", \"%s\" /*%d*/", hostname[i], active_i);
			if (active_i %5 == 0) printf("\n");
			if (active_i == NUM_OF_PEERS - 1) printf(" };\n");
			//================================  all_ip.cc
			freopen("all_ip.cc", "a", stdout);
			printf(", \"%s\" /*%d*/", inet_ntoa(*((struct in_addr *) nlp_host->h_addr)), active_i);
			if (active_i %5 == 0) printf("\n");
			if (active_i == NUM_OF_PEERS - 1) printf(" };\n");
		
			
		}


		freopen("/dev/tty", "w", stdout);
		printf("%d %d %s ---ok \n", i, active_i, hostname[i]);
		}

		//============================= peermakefile0;
		char makefilename[50] = {0};
		sprintf(makefilename, "p_peers/peermakefile%d", diff_i);
		freopen(makefilename, "w", stdout);
		printf("all: p_server ");
		for (int ii=0; ii < PEERS_ON_NODE; ii++)
		//all: pgetip p_server p_peer000 p_peer001 p_peer002 p_peer003 
			printf("p_peer%03d ", ii);
		printf("\np_server:  node.cc server.cc servermain.cc\n");
		printf("\tg++  -g -rdynamic -o p_server  node.cc server.cc servermain.cc -lpthread\n");
		for (int i1=diff_i*PEERS_ON_NODE, i2=0; i1<active_i; i1++, i2++){
			printf("p_peer%03d: node.cc peer.cc peermain_000.cc\n", i2);
			printf("\tg++  -g -rdynamic -D PEER_ID=%d -o p_peer%03d node.cc peer.cc   peermain_000.cc -lpthread\n", i1, i2);
		}
		
		printf("\nclean:\n\trm -rf p_server p_peer*");


		i++; 
		diff_i++;
	}

	printf("i=%d, active_i=%d\n", i, active_i);
		
	//================================  makefile
	freopen("makefile", "w", stdout);
	printf("all: pgetip p_server ");
	for (i=0; i < active_i; i++)
		//all: pgetip p_server p_peer000 p_peer001 p_peer002 p_peer003 
		printf("p_peer%03d ", i);
	
	printf("\npgetip: get_all_ip2.cc\n\tg++ -g -o pgetip get_all_ip2.cc\n");
//pgetip: get_all_ip.cc
	//g++ -g -o pgetip get_all_ip.cc
	printf("p_server:  node.cc server.cc servermain.cc\n");
	printf("\tg++  -g -rdynamic -o p_server  node.cc server.cc servermain.cc -lpthread\n");
//p_server:  node.cc server.cc servermain.cc
	//g++  -g -rdynamic -o p_server  node.cc server.cc servermain.cc -lpthread


//p_peer000: node.cc peer.cc peermain_000.cc
	//g++  -g -rdynamic -D PEER_ID=0 -o p_peers/p_peer000 node.cc peer.cc   peermain_000.cc -lpthread
	for (i=0; i<active_i; i++){
		printf("p_peer%03d: node.cc peer.cc peermain_000.cc\n", i);
		printf("\tg++  -g -rdynamic -D PEER_ID=%d -o p_peers/p_peer%03d node.cc peer.cc   peermain_000.cc -lpthread\n", i, i);
	}
		
	printf("\nclean:\n\trm -rf p_server pgetip p_peers/p_peer*");
//clean:  
	//rm -rf p_server pgetip p_peers/p_peer*

	return 1;
}
