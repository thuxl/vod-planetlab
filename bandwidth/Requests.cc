#include <stdio.h>
#include <stdlib.h>
#include "Requests.h"

#include <iostream>
using namespace std;

/*
 * 	freopen("rpoj2950input", "r", stdin);
 *
 *  freopen("rpoj2723output", "w", stdout);

	scanf("%d %d %d", &m, &n, &k);

	printf("%d ", p[i][j]);
 * */


namespace bandwidth
{

	Requests ::Requests(int time_p, int peeridx_p, int segidx_p, double pop_p)
    {
        time = time_p;
        peeridx = peeridx_p;
        segidx = segidx_p;
        pop = pop_p;
    }

	Requests::Requests  (const Requests &p)
	{
        time = p.time;
        peeridx = p.peeridx;
        segidx = p.segidx;
        pop = p.pop;
	}
    Requests & Requests::operator=(const Requests &p)
	{
        time = p.time;
        peeridx = p.peeridx;
        segidx = p.segidx;
        pop = p.pop;
	}
        /*int CompareTo(object obj)
        {
            Requests other = (Requests)obj;
            if (this.time != other.time)
            {
                return this.time - other.time;
            }
            if (this.pop != other.pop)
            {                
                return Math.Sign(this.pop - other.pop);
            }
            return this.segidx - other.segidx;
        }*/
}
