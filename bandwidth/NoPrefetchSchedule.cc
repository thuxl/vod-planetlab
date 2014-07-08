#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NoPrefetchSchedule.h"

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;




namespace bandwidth
{
   	int NoPrefetchSchedule::pre_time = -1;    //add by xl
   	double NoPrefetchSchedule::pre_maxflow = 0;
   	double NoPrefetchSchedule::pre_k=0;
	void NoPrefetchSchedule::Calc(TestCase *tc, Result &r)
    {
    	pre_time = -1;    //add by xl
       	pre_maxflow = 0;
       	pre_k=0;
        //sw = new StreamWriter("noprefetch_output.txt");
		//r.noPrefetchSubBands = new double[tc.param.t];
        bool** cacheMap = tc->CalcInitCacheMap();
        double max = 0;
        for (int time = 0; time < tc->param.t; time++)
        {
            double left = 0;
            double right = r.allServerSchedule;
            double eps = 1e-6;
            //Console.WriteLine("noPrefetch.calc: time={0}", time);
            //printf("noPrefetch.calc: time={%d}\n", time);
            while (left + eps < right)
            {
                double mid = (left + right) / 2;
                if (ok(mid, tc, cacheMap, time))
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }

            for (int i = (time == 0 ? 0 : tc->priorityListIndex[time - 1]); i < tc->priorityListIndex[time]; i++)
            {
                Requests req = tc->priorityList[i];
                cacheMap[req.peeridx][ req.segidx] = true;
            }
            r.noPrefetchSubBands[time] = left;
            max = std::max(left, max);
        }
        r.noPrefetchSchedule = max;
    }
        
	bool NoPrefetchSchedule::ok(double bw, TestCase *tc, bool** cacheMap, int time)
    {
        list<Requests> reqs; 
        for (int i = (time == 0 ? 0 : tc->priorityListIndex[time - 1]); i < tc->priorityListIndex[time]; i++)
        {
            Requests req = tc->priorityList[i];
            if (!cacheMap[req.peeridx][ req.segidx])
            {
                reqs.push_back(req);
            }
        }
        //======================================
        double total = 0;
        //foreach (Requests req in reqs)
		for (std::list<Requests >::iterator req = reqs.begin(); req != reqs.end(); ++req)
        {
            total += tc->segs[req->segidx].rate;
        }
        if (time == pre_time)
        {//已经算过 maxflow了，而且同一个时间段的 cache不变，所以即使需求变了，maxflow变化也不大。
            //Console.WriteLine("noprefetch.ok, old time,bw={0}, maxflow={1}, artificial flow={2};", bw, NetFlowCalc.maxflow, pre_maxflow);
            //printf("noprefetch.ok, old time,bw={%f}, maxflow={%f};artificial flow={%f};\n", bw, NetFlowCalc.maxflow, pre_maxflow);

            return bw + pre_maxflow + 1e-5 >= total;
            //return bw + NetFlowCalc.maxflow + 1e-5 >= total;
        }
        else
        {
            int n = tc->param.n;
            double temp_k = 0;
            for (int i = 0; i < n; i++)
            {
                for (int seg_i = 0; seg_i < tc->param.x; seg_i++)
                    if (cacheMap[i][ seg_i]) temp_k++;
            }
            temp_k = (double)temp_k / n;
            double flow1 = (double)tc->param.rate.miu_r * tc->param.n * tc->param.requestGenConfig.p_r;
			//double flow2=(double)tc->param.n * tc->param.miu_u * (1 - Math.Exp(-(tc->param.x * tc->param.n * tc->param.requestGenConfig.p_r / tc->param.m)));
            double flow2 = (double)tc->param.n * tc->param.miu_u * (1 - exp(-(temp_k * tc->param.n * tc->param.requestGenConfig.p_r / tc->param.m)));

            double near_flow = std::min(flow1, flow2);

            double artificial_flow=0;


            if (time == 0) 
                artificial_flow = 0;
            else if (time == 1)
                artificial_flow = (double)near_flow * 0.5;                
            else
            {
                artificial_flow = (double)(temp_k - pre_k) / temp_k * pre_maxflow * 0.9 + pre_maxflow;
                artificial_flow = std::min(artificial_flow, near_flow);
            }
            //Console.WriteLine("noprefetch.ok, new time{0}, artificial_flow={1};k={2}", time, artificial_flow, temp_k);
            //sw.WriteLine("noprefetch.ok, new time{0}, artificial_flow={1};k={2}", time, artificial_flow, temp_k);

            pre_time = time;
            pre_maxflow = artificial_flow;
            pre_k = temp_k;

            return bw + artificial_flow + 1e-5 >= total;
        }

        //return NetFlowCalc.check(tc, cacheMap, reqs, bw,sw);
    }
}
