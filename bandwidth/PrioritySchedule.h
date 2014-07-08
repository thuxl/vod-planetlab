#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdio.h>
#include <stdlib.h>
#include "TestCase.h"
#include "Result.h"


 

namespace bandwidth
{
	class TestCase;
	class Result;
    class PrioritySchedule
    {
	public:
		//static StreamWriter sw;
        static void Calc(TestCase *testCase, Result &r);

        static double innerCalc(TestCase *testCase, double lower, double upper);

	private:
		static bool ok(double bw, TestCase *tc);

	public:
		static int pre_time;
        static double pre_maxflow;
        static double pre_k;
	private:
		static bool subok(int last, int val, double bw, TestCase *tc, bool** cacheMap, int time);
    };
}
#endif
