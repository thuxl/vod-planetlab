#ifndef  EXP_H
#define  EXP_H
#include <stdio.h>
#include <stdlib.h>

#include "Param.h"
#include "TestCase.h"


namespace bandwidth
{
    class Exp
    {
	public: 
		Param param;

		Exp(const Param &p);

        double* run_avg(int seed0, int cnt);
    };
}
#endif
