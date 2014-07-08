#ifndef LOWERBOUND_H
#define LOWERBOUND_H

#include <stdio.h>
#include <stdlib.h>
#include "TestCase.h"
#include "Result.h"


namespace bandwidth
{
	class TestCase;
	class Result;
    class LowerBound
    {
	public:
		static void Calc(TestCase *tc, Result &r);
    };
}
#endif
