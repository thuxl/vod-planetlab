#include <stdio.h>
#include <stdlib.h>
#include "LowerBound.h"

#include <iostream>
using namespace std;



namespace bandwidth
{
	void LowerBound::Calc(TestCase *tc, Result &r)
    {
        double v = (1e-6 + tc->accumulateReq[tc->param.t] - (+tc->totalPeerBandwidth * (tc->param.t - 1) + tc->initPeerBW)) / tc->param.t;
        r.lowerBound = r.noPrefetchSubBands[0];  //实际就是非预取时第一时间段的 需求。因为 默认peer一开始没有segs
        if (v > r.lowerBound)
        {
            //Console.WriteLine("{0} {1}", v, r.lowerBound);
            r.lowerBound = v;
        }
    }
}
