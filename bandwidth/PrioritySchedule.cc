#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PrioritySchedule.h"

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;



namespace bandwidth
{
	int PrioritySchedule::pre_time = -1;
    double PrioritySchedule::pre_maxflow =0;
    double PrioritySchedule::pre_k = 0;
        
	void PrioritySchedule::Calc(TestCase *testCase, Result &r)
    {
        double v1 = innerCalc(testCase, r.lowerBound, r.allServerSchedule);
        //double v2 = innerCalc(testCase, 0, 1e12, true);
        //Console.WriteLine("{0} {1}", v1, v2);
        r.prioritySchedule = v1;
    }

    double PrioritySchedule::innerCalc(TestCase *testCase, double lower, double upper)
    {
        double eps = 1e-6;
        while (lower + eps < upper)
        {
            double mid = (lower + upper) / 2;
            if (ok(mid, testCase))
            {
                upper = mid;
            }
            else
            {
                lower = mid;
            }
        }
        return upper;
    }

	bool PrioritySchedule::ok(double bw, TestCase *tc)
    {
        Param param = tc->param;
        bool** cacheMap = tc->CalcInitCacheMap();
        int last = 0;
        pre_time = -1;
        pre_maxflow =0;
        pre_k = 0;
        //Console.WriteLine(bw);
        for (int time = 0; time < param.t; time++)
        {
            //Console.WriteLine("bw={0}, PrioritySchedule: time={1}", bw, time);
            int left = tc->priorityListIndex[time];
            if (!subok(last, left, bw, tc, cacheMap, time))
            {
                return false;
            }
            left = std::max(left, last);
            double allBw = tc->totalPeerBandwidth + bw;
            int right = last;
            while (right < tc->priorityList.size() && allBw > 1e-6)
            {
                allBw -= tc->segs[tc->priorityList[right].segidx].rate;
                right++;
            }
            if (right == tc->priorityList.size())
                right++;
            if (left >= right)
                return false;
            while (left + 1 < right)
            {
                int mid = (left + right) / 2;
                if (subok(last, mid, bw, tc, cacheMap, time))
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            //best = left;
            for (int i = last; i < left; i++)
            {
                cacheMap[tc->priorityList[i].peeridx][ tc->priorityList[i].segidx] = true;
            }
            last = left;
            //Console.WriteLine(last);
        }
        return last == tc->priorityList.size();
    }

	bool PrioritySchedule::subok(int last, int val, double bw, TestCase *tc, bool** cacheMap, int time)
    {
        list<Requests> reqs; 
        for (int i = last; i < val; i++)
        {
            Requests req = tc->priorityList[i];
            if (!cacheMap[req.peeridx][ req.segidx])
            {
                reqs.push_back(req);
            }
        }

        //=====by xl
        double total = 0;
        //foreach (Requests req in reqs)
		for (std::list<Requests >::iterator req = reqs.begin(); req != reqs.end(); ++req)
        {
            total += tc->segs[req->segidx].rate;
        }
        if (time == pre_time)
        {//已经算过 maxflow了，而且同一个时间段的 cache不变，所以即使需求变了，maxflow变化也不大。
            //Console.WriteLine("priority.subok, old time{3},bw={0}, maxflow={1}, artificial flow={2};", bw, NetFlowCalc.maxflow, pre_maxflow, time);
            //sw.WriteLine("priority.subok, old time{3},bw={0}, maxflow={1};artificial flow={2};", bw, NetFlowCalc.maxflow, pre_maxflow, time);

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

            double artificial_flow = 0;


            if (time == 0)
                artificial_flow = 0;
            else if (time == 1)
                artificial_flow = (double)near_flow * 0.5;
            else
            {
                artificial_flow = (double)(temp_k - pre_k) / temp_k * pre_maxflow * 0.9 + pre_maxflow;
                artificial_flow = std::min(artificial_flow, near_flow);
            }
            //Console.WriteLine("priority.subok, new time{0}, artificial_flow={1};k={2}", time, artificial_flow, temp_k);
            //sw.WriteLine("priority.subok, new time{0}, artificial_flow={1};k={2}", time, artificial_flow, temp_k);

            pre_time = time;
            pre_maxflow = artificial_flow;
            pre_k = temp_k;

            return bw + artificial_flow + 1e-5 >= total;
        }

        //return NetFlowCalc.check(tc, cacheMap, reqs, bw, sw);
    }
}
