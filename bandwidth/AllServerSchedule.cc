#include <stdio.h>
#include <stdlib.h>
#include "AllServerSchedule.h"

#include <iostream>
#include <algorithm>
using namespace std;



namespace bandwidth
{
	void AllServerSchedule::Calc(TestCase *tc, Result &r)
    {
        double max = 0;
        Param param(tc->param);
        //r.totalReqs = new double[param.t];
        for (int i = 0; i < param.t; i++)
        {
            double v = 0;
            for (int j=0; j<param.n; j++)
            {
                int idx = tc->peers[j].requests[i];
                if (idx != -1)
                {
                    v += tc->segs[idx].rate;
                }
            }
            r.totalReqs[i] = v;
            max = std::max(max, v);
        }
        r.allServerSchedule = max;
    }
}
