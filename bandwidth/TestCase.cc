#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TestCase.h"

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/*
 * 	freopen("rpoj2950input", "r", stdin);
 *  freopen("rpoj2723output", "w", stdout);
	scanf("%d %d %d", &m, &n, &k);
	printf("%d ", p[i][j]);
 * */


namespace bandwidth
{
        //RandomGen randomGen;

	TestCase::TestCase(const Param &param_p, int seed)
    {
        param = param_p;
        randomGen.SetSeed (seed);
        movies = Movie::GenMovies(param.m, param);
        segs = Segment::GenSegment(movies, param, randomGen);
        peers = Peer::GenPeers(param, movies, randomGen);
        PrepareData();
		Gen_testcase();

    }

	void TestCase::Gen_testcase()
	{
		freopen("../configure.cc", "w", stdout);
		
		
		printf("const int peer_reqid[%d][%d]={ ", param.n, param.t);
		for (int i=0; i<param.n; i++) {
			printf("\t{ ");
			for (int j = 0; j < param.t; j++){
				if (j == param.t - 1)
					printf("%d ", peers[i].requests[j]);
				else
					printf("%d, ", peers[i].requests[j]);
			}

			if (i == param.n - 1)
				printf("} ");
			else
				printf("}, \n");
		}
		printf(" };\n");

		printf("const double peer_reqbw[%d][%d]={ ", param.n, param.t);
		for (int i=0; i<param.n; i++) {
			printf("\t{ ");
			for (int j = 0; j < param.t; j++){
				int reqid=peers[i].requests[j];
				if (j == param.t - 1){
					if (reqid != -1) printf("%f ", segs[reqid].rate);
					else printf("0 " );
				}
				else{
					if (reqid != -1) printf("%f, ", segs[reqid].rate);
					else printf("0, " );
				}
			}

			if (i == param.n - 1)
				printf("} ");
			else
				printf("}, \n");
		}
		printf(" };\n");

		printf("const double peer_outband[%d]={ ", param.n );
		for (int i=0; i<param.n; i++) {
			if (i == param.n - 1)
				printf("%f ", peers[i].upBand);
			else
				printf("%f, ", peers[i].upBand);
		}
		printf(" };\n");



		printf("const bool initcache[%d][%d]={ ", param.n, param.x);
		for (int i=0; i<param.n; i++) {
			printf("\t{ ");
			for (int j = 0; j < param.x; j++){
				if (j == param.x - 1){
					if (cacheMaps[0][i][j] == true) printf("1 " );
					else 						    printf("0 " );
				}
				else{
					if (cacheMaps[0][i][j] == true) printf("1, " );
					else 						    printf("0, " );
				}
			}

			if (i == param.n - 1)
				printf("} ");
			else
				printf("}, \n");
		}
		printf(" };\n");


		//freopen("/dev/tty", "w", stdout);
	}

	void TestCase::PrepareData()
    {
        totalPeerBandwidth = 0;
        for (int i = 0; i < param.n; i++)
        {
            totalPeerBandwidth += peers[i].upBand;
        }
        CalcStepCacheMaps();
        PreparePriorityList();
        //MaskType.SetBitsRequired(priorityList.Count);
        accumulateReq = new double[param.t + 1]();
        for (int time = 1; time <= param.t; time++)
        {
            accumulateReq[time] = accumulateReq[time - 1];
        //list<Requests>[] reqList;
            //foreach(Requests req in reqList[time - 1])
			for (std::list<Requests>::iterator req = reqList[time - 1].begin(); req != reqList[time - 1].end(); ++req)
            {//[time]记录0到 time-1 的 请求之和。
                accumulateReq[time] += segs[req->segidx].rate;
            }
        }
    }

    //	NoPrefetchSchedule::pre_time = -1;    //add by xl
    //	NoPrefetchSchedule::pre_maxflow = 0;
    // 	NoPrefetchSchedule::pre_k=0;
	void TestCase::Calc(Result &r)
    {
		time_t start,end,time;
		start = clock();

        //should be calculated in this order!
		AllServerSchedule::Calc(this, r);
		NoPrefetchSchedule::Calc(this, r);
		LowerBound::Calc(this, r);
		PrioritySchedule::Calc(this, r);
        end = clock();
		time=end - start;
        r.timeUsedForSchedule =((float)time)/CLOCKS_PER_SEC; //difftime(end, start);
        //if (Config.CALC_OPT)
       // {
        //    OptimalBandwidth.Calc(this, r);
        //}
		//cout << "elapsed time:" << time << endl;
        //r.timeUsedForOptimal = stopWatch.Elapsed.TotalSeconds;
    }

	bool TestCase::req_compare(const Requests &first, const Requests &other)
	{
            if (first.time != other.time)
            {
                return (first.time < other.time) ;
            }
            if (first.pop != other.pop)
            {                
                return (first.pop < other.pop) ;
            }
            return (first.segidx < other.segidx) ;
	}

    void TestCase::PreparePriorityList()
    {
        //reqList = new list<Requests> [param.t];
        reqList.assign(param.t, list<Requests>() );
        //priorityList = new list<Requests>();
        priorityListIndex = new int[param.t]();
        int cur = 0;
        for (int time = 0; time < param.t; time++)
        {
            //reqList[time] = new list<Requests>();
            for (int peeridx = 0; peeridx < param.n; peeridx++)
            {
                int pieceidx = peers[peeridx].requests[time];
                if (pieceidx != -1)
                {
                    Requests req  (time, peeridx, pieceidx, segs[pieceidx].pop);
                    priorityList.push_back(req);
                    reqList[time].push_back(req);
                    cur++;
                }
            }
            priorityListIndex[time] = cur;
        }
        std::sort (priorityList.begin(), priorityList.end(), TestCase::req_compare);
            //foreach (Requests r in priorityList)
            //{
            //    Console.WriteLine(r.time + " " + r.pieceidx);
            //}
    }



    bool** TestCase::CalcInitCacheMap()
    {
        return cacheMaps[0];
    }


	void TestCase::CalcStepCacheMaps()
    {
        cacheMaps = new bool** [param.t];
		for (int ii=0; ii<param.t; ii++)
		{
			cacheMaps[ii] = new bool* [param.n];
			for (int j=0; j<param.n; j++){
				cacheMaps[ii][j] = new bool [param.x];
				for (int k=0; k<param.x; k++)
					cacheMaps[ii] [j] [k] = false;
			}

		}
        initPeerBW = 0;
        //cacheMaps[0] = new bool[param.n, param.x];  //二维数组，0时间段 n个peers， 对应 x个chunks
		

        for (int p = 0; p < param.n; p++)
        {
            //foreach (int idx in peers[p].initCache)  //initCache is list<int>
			for (std::list<int>::iterator idx = peers[p].initCache.begin(); idx != peers[p].initCache.end(); ++idx)
            {
                cacheMaps[0][p][*idx] = true;
            }
            if (peers[p].initCache.size() > 0)
            {
                initPeerBW += peers[p].upBand;
            }
            //cacheMaps[0][p][randomGen.Uniform(0, param.x)] = true;
			for (int j=0; j<param.x; j++) {
				cacheMaps[0][p][j] = randomGen.boolUniform(param.initcache_uniform_exp);
			}
        }
        
		/*if (Config.CALC_OPT)
        {
            for (int time = 1; time < param.t; time++)
            {
                cacheMaps[time] = Util.copy(cacheMaps[time - 1]);
                for (int i = 0; i < param.n; i++)
                {
                    int idx = peers[i].requests[time - 1];
                    if (idx != -1)
                    {
                        cacheMaps[time][i, idx] = true;
                    }
                }
            }
        }*/
    }
	TestCase::~TestCase()
	{
		for (int ii=0; ii<param.t; ii++)
		{
			for (int j=0; j<param.n; j++){
				delete cacheMaps[ii][j]; 
			}
			delete cacheMaps[ii];

		}
		delete cacheMaps;

		delete[] movies;
		delete[] segs;
		delete[] peers;
		delete[] accumulateReq;
        
		//vector< list<Requests> >
		reqList.clear();
        //list<Requests> 
		priorityList.clear();
	}
}
