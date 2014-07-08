#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "Param.h"
#include "RandomGen.h"
#include "Peer.h"
#include "Movie.h"
#include "Requests.h"
#include "Result.h"
#include "Segment.h"
#include "Exp.h"
#include "../common.h"

/*
 * 	freopen("rpoj2950input", "r", stdin);
 *  freopen("rpoj2723output", "w", stdout);
	scanf("%d %d %d", &m, &n, &k);
	printf("%d ", p[i][j]);
 * */


namespace bandwidth
{

	double* go(int m, int x_m, int n, int t, double p_r, double miu_u, double sigma_u, double init_cache_p)
    {
        //==================================================
        //m = 50; x_m = 1; n = 20; t = 10; p_r = 0.5; miu_u = 200; sigma_u = 50;
        Param p = Param(m, x_m, n, t, Peer::DefaultInitRequestGenConfig(p_r), miu_u, sigma_u,
            Rate::DefaultRate(Rate::Normal),
            Movie::DefaultPopDistribution(PopDistribution::Uniform),
            Peer::DefaultInitCacheConfig(InitCacheConfig::NoCache),
			init_cache_p
			);
        double* rs = Exp(p).run_avg(-1, 1);
        return rs;
    }

	void run4()
    {
		int m = NUM_OF_MOVIES		;
    	int x_m = NUM_OF_SEGS_EACH_MOVIE		;  //每个电影包含的片段数
    	int n = NUM_OF_PEERS			;
    	int t = NUM_OF_T;
 
        //int m = 30;
        //int x_m = 1;  //每个电影包含的片段数
        //int n = 20;
        //int t = 10;
        double p_r = 0.5;
        double miu_u = 200;
        double sigma_u = 50;
		double init_cache_exp = INIT_CACHE_EXP;

        //freopen("sch_n.txt", "w", stdout);
        printf("varying n. server band: prioritySchedule noPrefetchSchedule allServerSchedule overhead\n");
        //for (int vn = 3; vn <= 30; vn += 3)                   
        //for (int vn = 1000; vn <= 1000; vn += 1000)
        //{ 
			double* rs = go(m, x_m, n, t, p_r, miu_u, sigma_u, init_cache_exp );

			printf("const double server_outbw=%f;\n", rs[0]);
		
			freopen("/dev/tty", "w", stdout);
            printf("{%d}\t{%f}\t{%f}\t{%f}\t{%fs}\n", n, rs[0], rs[1], rs[2], rs[3]);
		//}

            
    }

}

int main()
{
	bandwidth::run4();

	return 1;
}
