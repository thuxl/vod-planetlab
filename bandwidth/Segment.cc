#include <stdio.h>
#include <stdlib.h>

#include "Segment.h"

#include <iostream>
using namespace std;



namespace bandwidth
{

	Segment::Segment()
	{
	}
    Segment::Segment(const Segment &s)
	{
        rate = s.rate; //请求这个段的带宽
        idx = s.idx;
        pop = s.pop;
	}
        
	Segment& Segment::operator=(const Segment &s)
	{
        rate = s.rate; //请求这个段的带宽
        idx = s.idx;
        pop = s.pop;
	}

	Segment::Segment(Param &param, int idx_p, double pop_p, RandomGen &randomGen)
    {
        rate = randomGen.genNormal(param.rate.miu_r, param.rate.sigma_r);  //请求这个段的带宽
        idx = idx_p;
        pop = pop_p;
    }
	void Segment::Set(Param &param, int idx_p, double pop_p, RandomGen &randomGen)
    {
        rate = randomGen.genNormal(param.rate.miu_r, param.rate.sigma_r);  //请求这个段的带宽
        idx = idx_p;
        pop = pop_p;
    }
	void Segment::Set(Param &param, int idx_p, double pop_p, double rate_p)
    {
        rate = rate_p; //请求这个段的带宽
        idx = idx_p;
        pop = pop_p;
    }

    Segment* Segment::GenSegment(Movie* movies, Param &param, RandomGen &randomGen)
    {
        int m = param.m;
        int x_m = param.x_m;
        Segment* ret = new Segment[m * x_m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < x_m; j++)
            {
                int idx = i * x_m + j;
                //Segment seg (param, idx, movies[i].pop, randomGen);
                ret[idx].Set (param, idx, movies[i].pop, randomGen);
                movies[i].segs.push_back(ret[idx]);
            }
        }
        //for test fix
        //===========================================
        return ret;
    }
}
