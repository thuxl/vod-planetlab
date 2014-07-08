#ifndef SEGMENT_H
#define SEGMENT_H


#include <stdio.h>
#include <stdlib.h>

#include "RandomGen.h"
#include "Param.h"
#include "Movie.h"


namespace bandwidth
{
	class Param;
	class Movie;
	class Segment
    {
	public:
		double rate;
        int idx;
        double pop;

        Segment();
        Segment(const Segment &s);
        Segment(Param &param, int idx, double pop, RandomGen &randomGen);
        Segment& operator=(const Segment &s);
        void Set(Param &param, int idx, double pop, RandomGen &randomGen);
        void Set(Param &param, int idx, double pop, double rate);

        static Segment* GenSegment(Movie* movies, Param &param, RandomGen &randomGen);
    };
}
#endif
