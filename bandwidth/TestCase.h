
#ifndef TESTCASE_H
#define TESTCASE_H
#include <stdio.h>
#include <stdlib.h>

#include <list>
#include <vector>
using namespace std;

#include "Requests.h"
#include "Result.h"
#include "Movie.h"
#include "Segment.h"
#include "Peer.h"
#include "AllServerSchedule.h"
#include "NoPrefetchSchedule.h"
#include "LowerBound.h"
#include "PrioritySchedule.h"

namespace bandwidth
{

	class AllServerSchedule;
	class NoPrefetchSchedule;
	class LowerBound;
	class PrioritySchedule;
    class TestCase
    {
	public:
		Param param;
        Movie* movies;
        Segment* segs;
        Peer* peers;
        double totalPeerBandwidth;
        double* accumulateReq;
        vector< list<Requests> > reqList;
        vector<Requests> priorityList;
        int* priorityListIndex;
        bool*** cacheMaps;   //三维数组 (time, peer, segment)
        double initPeerBW;
        RandomGen randomGen;

        TestCase(const Param & param, int seed);
		void Gen_testcase(void);
		TestCase();
		~TestCase();

	private:
		void PrepareData();

	public:
		void Calc(Result &r);

		static bool req_compare(const Requests &first, const Requests &second);
        void PreparePriorityList();



        bool** CalcInitCacheMap();


	private:
		void CalcStepCacheMaps();
    };
}
#endif
