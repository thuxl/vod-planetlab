#ifndef REQUESTS_H
#define REQUESTS_H

#include <stdio.h>
#include <stdlib.h>



namespace bandwidth
{
    class Requests 
    {
	public: 
		int time;
        int peeridx;
        int segidx;
        double pop;

        Requests(int time, int peeridx, int segidx, double pop);
        Requests (const Requests &p);
        Requests & operator=(const Requests &p);

    };
}

#endif
