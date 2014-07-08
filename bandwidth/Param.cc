#include <stdio.h>
#include <stdlib.h>
#include "Param.h"

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

	RequestGenConfig::RequestGenConfig()
	{
        requestGenType = RequestGenConfig::Probability;
    	startType = RequestGenConfig::Start;
	}
	RequestGenConfig::RequestGenConfig(double p_r_p)
    {
        p_r = p_r_p;
        requestGenType = RequestGenConfig::Probability;
    	startType = RequestGenConfig::Start;
    }

    RequestGenConfig::RequestGenConfig(int** givenReq_p)
    {
        givenReq = givenReq;
        requestGenType = RequestGenConfig::Given;
    	startType = RequestGenConfig::Start;
    }

	Rate::Rate()
	{
       	miu_r = 400; //requrement for bandwidth, used in Segment.cc
        sigma_r = 50;
   		//rates = new double[4];
		rates[0]= 200;
		rates[1]= 400;
		rates[2]= 800;
		rates[3]= 1600;
	}
	Rate::~Rate()
	{
   		//delete []rates;
	}

    Rate Rate::NormalRate(double miu_r_p, double sigma_r)
    {
        Rate r;// = Rate();
        r.miu_r = miu_r_p;
        r.sigma_r = sigma_r;
        r.distribute = Rate::Normal;
        return r;
    }
    Rate Rate::DefaultRate(Rate::RateDistribution distribute)
    {
        Rate r; //= Rate();
        r.distribute = distribute;
        return r;
    }

	InitCacheConfig::InitCacheConfig(InitCacheConfig::ConfigType type_p)
    {
		k = 2;
        q = 0.9;
        type = type_p;
    }


	InitCacheConfig::InitCacheConfig()
    {
		k = 2;
        q = 0.9;
    }

	Param::Param(int m_p, int x_m_p, int n_p, int t_p, RequestGenConfig requestGenConfig_p, double miu_u_p, double sigma_u_p,
            Rate rate_p, PopDistribution popDistribution_p, InitCacheConfig initCacheConfig_p, double initcache_uniform_exp_p )
    {
        m = m_p;
        x_m = x_m_p;
        n = n_p;
        t = t_p;
        requestGenConfig = requestGenConfig_p;
        miu_u = miu_u_p;
        sigma_u = sigma_u_p;
		initcache_uniform_exp = initcache_uniform_exp_p;
        rate = rate_p;
        popDistribution = popDistribution_p;
        initCacheConfig = initCacheConfig_p;
        x = x_m * m;   //总的片段数
    }


	Param & Param::operator=(const Param &p)
	{
        m = p.m;
        x_m = p.x_m;
        n = p.n;
        t = p.t;
        requestGenConfig = p.requestGenConfig;
        miu_u = p.miu_u;
        sigma_u = p.sigma_u;
		initcache_uniform_exp = p.initcache_uniform_exp;
        rate = p.rate;
        popDistribution = p.popDistribution;
        initCacheConfig = p.initCacheConfig;
        x = x_m * m;   //总的片段数
    }


	Param::Param(const Param &p)
	{
		m = p.m;
        x_m = p.x_m;
        n = p.n;
        t = p.t;
        requestGenConfig = p.requestGenConfig;
        miu_u = p.miu_u;
        sigma_u = p.sigma_u;
		initcache_uniform_exp = p.initcache_uniform_exp;
        rate = p.rate;
        popDistribution = p.popDistribution;
        initCacheConfig = p.initCacheConfig;
        x = x_m * m;   //总的片段数

	}


}
