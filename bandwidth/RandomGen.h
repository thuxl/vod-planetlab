#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;




namespace bandwidth
{
    class RandomGen
    {
	public:
		RandomGen();
		RandomGen(int seed);
		void SetSeed(int seed);
		~RandomGen();
        //Random rand;
        double genNormal(double miu, double sigma);
		double NextDouble();
		int Next(int max);
		int Uniform(int min_v, int max_v);
		bool boolUniform(double exp);
        double normals[10000];
    };
}

#endif
