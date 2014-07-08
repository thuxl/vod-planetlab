#include <stdio.h>
#include <stdlib.h>
#include "Peer.h"

#include <iostream>
#include <algorithm>
using namespace std;


namespace bandwidth
{

    Peer* Peer::GenPeers(Param &param, Movie* movies, RandomGen &randomGen)
    {
        Peer* peers = new Peer[param.n];
        for (int i = 0; i < param.n; i++)
        {
            peers[i].genPeer(param, movies, i, randomGen);
        }

        //for test fix
        //============================================
        return peers;
    }

	void Peer::genPeer(Param &param, Movie* movies, int peeridx, RandomGen &randomGen)
    {
        peeridx = peeridx;
        upBand = randomGen.genNormal(param.miu_u, param.sigma_u);
        initCache = genInitCache(param);
        genRequests(param, movies, randomGen, peeridx);
    }

	Peer::~Peer()
	{
        delete [] requests;
	}

    void Peer::genRequests(Param &param, Movie* movies, RandomGen &randomGen, int peeridx)
    {//针对peer [peeridx] 生成 它的 t 个时间段的 请求。
        if (param.requestGenConfig.requestGenType == RequestGenConfig::Probability)
        {
			requests = new int[param.t];
			for (int t_i=0; t_i < param.t; t_i++) requests [t_i] = -1;
            bool* cached = new bool[param.x] ();//开始时（0时间段）， 当前peer的 所有 x个 cache情况
            if (param.popDistribution.popType == PopDistribution::Uniform)
            {
                int cur = 0;
                while (cur < param.t)
                {
                    if (randomGen.NextDouble() < param.requestGenConfig.p_r)
                    {
                        Movie movie = movies[randomGen.Next(param.m)];  //得到随机的电影
                        int start;
                        if (param.requestGenConfig.startType == RequestGenConfig::Start)
                        {
                            start = 0;
                        }
                        else
                        {
                            throw param.requestGenConfig.startType;
                        }
                        int len = randomGen.Next(movie.segs.size() - start) + 1; //the size of movie's segs. //请求次数不能大于电影 seg数目
                        len = std::min(param.t - cur, len);
                        for (int j = 0; j < len; j++)
                        {
                            Segment seg = movie.segs[start + j];
                            if (cached[seg.idx])
                            {//不同时间段 但是是重复请求，不予考虑
                                //if (Config.DEBUG)
                                ////{
                                    //Console.WriteLine("Remove dup req! time {0} peer {1} seg {2}", cur, peeridx, seg.idx);
                                //}
                            }
                            else
                            {
                                requests [cur] = seg.idx;
                                cached[seg.idx] = true;
                            }
                            cur++; //每个时间段 最多请求一个 seg
                        }
                    }
                    else
                    {
                        requests [cur] = -1;
                        cur++;
                    }
                }
            }
            else
            {
                throw param.popDistribution.popType ;
            }
            delete [] cached;
        }
        else//if (param.requestGenConfig.requestGenType == RequestGenConfig.RequestGenType.Given)
        {
            requests = param.requestGenConfig.givenReq[peeridx];
        }
    }

    list<int> Peer::genInitCache(Param &param)
    {
        if (param.initCacheConfig.type == InitCacheConfig::NoCache)
        {
            return list<int>();
        }
        else
        {
			printf("error in Peer::genInitCache(Param param).\n");
        }
    }


	
        
    InitCacheConfig Peer::DefaultInitCacheConfig(InitCacheConfig::ConfigType type)
    {
        InitCacheConfig conf (type);
        return conf;
    }

	
	RequestGenConfig Peer::DefaultInitRequestGenConfig(double p_r)
	{
		RequestGenConfig  reqconfig(p_r);
		return reqconfig;
	}

}
