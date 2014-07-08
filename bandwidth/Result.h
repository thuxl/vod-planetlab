#ifndef RESULT_H
#define RESULT_H
#include <stdio.h>
#include <stdlib.h>



namespace bandwidth
{
    class Result
    {
	public:
		//time
        double prioritySchedule;
        double noPrefetchSchedule;
        double allServerSchedule;
        double timeUsedForSchedule;


		double lowerBound;
        double optimalBandwidth;
        double eps;
        double* noPrefetchSubBands;
        double* totalReqs;
        double timeUsedForOptimal;
	
		
		Result();
		Result(int time);
		~Result();

    };



}
#endif
