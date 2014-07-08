#ifndef ALLSERVER_H
#define ALLSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include "Param.h"
#include "TestCase.h"
#include "Result.h"




namespace bandwidth
{
	class TestCase ;
	class Result ;
	class Param ;
    class AllServerSchedule
    {
	public:
		static void Calc(TestCase *tc, Result &r);
    };
}
#endif
