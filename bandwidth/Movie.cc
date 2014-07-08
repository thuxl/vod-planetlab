#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Movie.h"

#include <iostream>
using namespace std;



namespace bandwidth
{
	Movie::Movie()
	{
		pop = 1;
       	//segs = list<Segment>();
	}
	Movie::~Movie()
	{
		segs.clear();
	}

	Movie::Movie(int idx, Param &param)
    {
        if (param.popDistribution.popType == PopDistribution::Uniform)
        {
            pop = 1;
        }
        else if (param.popDistribution.popType == PopDistribution::Zipf)
        {
            pop = 1 / pow(idx, param.popDistribution.alpha);
        }
       	//segs = list<Segment>();
    }

	void Movie::Set(int idx, Param &param)
    {
        if (param.popDistribution.popType == PopDistribution::Uniform)
        {
            pop = 1;
        }
        else if (param.popDistribution.popType == PopDistribution::Zipf)
        {
            pop = 1 / pow(idx, param.popDistribution.alpha);
        }
       	//segs = list<Segment>();
    }
    Movie* Movie::GenMovies(int m, Param &param)
    {
        Movie* movies = new Movie[m];
        for (int i = 0; i < m; i++)
        {
            movies[i].Set (i, param);
        }
        return movies;
    }

    PopDistribution Movie::DefaultPopDistribution(int popType)
    {
        PopDistribution popDistribution ;
        popDistribution.popType = (PopDistribution::PopType)popType;
        return popDistribution;
    }
}
