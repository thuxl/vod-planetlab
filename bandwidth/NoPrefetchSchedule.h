#ifndef NOPREFETCH_H 
#define NOPREFETCH_H 

#include <stdio.h>
#include <stdlib.h>

#include "TestCase.h"
#include "Result.h"


namespace bandwidth
{
	class TestCase;
	class Result;
    class NoPrefetchSchedule
    {
	public:
		//static StreamWriter sw;
        static int pre_time;    //add by xl
        static double pre_maxflow;
        static double pre_k;
        static void Calc(TestCase *tc, Result &r);
        
	private:
		static bool ok(double bw, TestCase *tc, bool** cacheMap, int time);
    };
}
#endif
