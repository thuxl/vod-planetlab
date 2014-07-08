#include <stdio.h>
#include <stdlib.h>
#include "Exp.h"

#include <iostream>
#include <string>
using namespace std;



namespace bandwidth
{

	Exp::Exp(const Param &p)
    {
        param =p; //use copy construction.
    }

    double* Exp::run_avg(int seed0, int cnt)
    {
        const int rc = 3;
        double* ret = new double[rc+1]();  //last is overhead time.
        string filename = "sch_time_n_" + param.n;
		//freopen(filename, "w", stdout);
        for (int i = 0; i < cnt; i++)
        {
            int seed = (seed0 >= 0) ? seed0 + i : seed0;
            TestCase case1 (param, seed);
			//freopen("fix_parameters2", "w", stdout);
            //add by xl for test
            //printf("i = %d, Program.cs\n go()\n", i);
            //printf("m={%d}; x_m={%d}; n={%d}; t={%d}; p_r={%f}; miu_u={%f}; sigma_u={%f};\n",
             //       param.m, param.x_m, param.n, param.t, param.requestGenConfig.p_r, param.miu_u, param.sigma_u);
            //printf("此用例可以进入bitseqgen.cs innerGen 后续程序\n");

            //printf("Peer.cs\n GenPeers()\n");
            //for (int pn = 0; pn < param.n; pn++)
            //{
                //printf("peers[%d].requests= new int[%d] {", pn, param.t);
             //   for (int prn = 0; prn < param.t; prn++)
              //  {
               //     if (prn == 0)
                //        ;//printf("%d", case1.peers[pn].requests[prn]);
                 //   else
                        //;//printf(", %d", case1.peers[pn].requests[prn]);
               // }
                //printf("};\n");
                //printf("peers[%d].upBand= %f;\n", pn, case1.peers[pn].upBand);
            //}
            //printf("\nSegment.cs\n GenSegment()\n");
            //for (int mn = 0; mn < param.m; mn++)
            //{
             //   for (int mxn = 0; mxn < param.x_m; mxn++)
              //  {
               //     int idx = mn * param.x_m + mxn;
                    //printf("ret[%d].rate=	%f;\n", idx, case1.segs[idx].rate);
                //}
            //}

            Result res(param.t);
			case1.Calc(res);
            ret[0] += res.prioritySchedule;
            ret[1] += res.noPrefetchSchedule;
            ret[2] += res.allServerSchedule;
            ret[3] += res.timeUsedForSchedule;
                    
            //printf("timeUsedForSchedule=%f\n", res.timeUsedForSchedule);

        }
        for (int i = 0; i <= rc; i++)
        {
            ret[i] /= cnt;
        }
        return ret;
    }
}
