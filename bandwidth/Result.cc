#include <stdio.h>
#include <stdlib.h>
#include "Result.h"

#include <iostream>
using namespace std;



namespace bandwidth
{
	
	Result::~Result()
	{
        delete [] noPrefetchSubBands;
        delete [] totalReqs;
	}
	Result::Result()
	{
        prioritySchedule = 0;
        noPrefetchSchedule = 0;
        allServerSchedule = 0;
        timeUsedForSchedule = 0;


		lowerBound = 0;
        optimalBandwidth = 0;
        eps = 0;
        noPrefetchSubBands = NULL;
        totalReqs = NULL;
        timeUsedForOptimal = 0;
	

	}

	Result::Result(int t)
	{
        prioritySchedule = 0;
        noPrefetchSchedule = 0;
        allServerSchedule = 0;
        timeUsedForSchedule = 0;
		noPrefetchSubBands = new double[t]();
		totalReqs = new double[t]();
		
		lowerBound = 0;
        optimalBandwidth = 0;
        eps = 0;
        timeUsedForOptimal = 0;
	}
}
