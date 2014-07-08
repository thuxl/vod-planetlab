
#ifndef PARAM_H
#define PARAM_H

#include <stdio.h>
#include <stdlib.h>

//#include "Peer.h"
//#include "Movie.h"


namespace bandwidth
{
	//class PopDistribution ;


	
	class PopDistribution
    {
	public:

		enum PopType
    	{
        	Uniform,
        	Zipf
    	};
		
        double alpha;
		PopType popType;
		
		PopDistribution () {alpha = 1;}
		PopDistribution & operator=(const PopDistribution &p)
		{
        	alpha = p.alpha;
			popType = p.popType;
		}
    };

	
	class RequestGenConfig
    {
	public: 
		double p_r;
        RequestGenConfig();
        RequestGenConfig(double p_r);
        RequestGenConfig(int** givenReq_p);

        RequestGenConfig& operator=(const RequestGenConfig &p)
		{
			p_r = p.p_r;
			requestGenType = p.requestGenType;
			startType = p.startType;
			givenReq = p.givenReq;
		}
        enum RequestGenType
        {
            Given,
            Probability
        } requestGenType;

        int** givenReq;
        enum StartType
        {
            Start,
            StartUniformMixed
        } startType;
    };


	class InitCacheConfig
    {
	public:

		enum ConfigType
		{
           	NoCache,
       		PowerProportionalCache
		};
		int k;
        double q;
        ConfigType type;

        InitCacheConfig();
        InitCacheConfig(ConfigType type);
		InitCacheConfig& operator=(const InitCacheConfig &p)
		{
			k = p.k;
        	q = p.q;
        	type = p.type;
		}
    };


    class Rate
    {
	public:
		enum RateDistribution
        {
            Normal,
            Segment
        };
        double miu_r; //requrement for bandwidth, used in Segment.cc, in kbps
        double sigma_r;
        double rates[4];
        RateDistribution distribute;

		Rate();
		~Rate();
        static Rate NormalRate(double miu_r_p, double sigma_r);
        static Rate DefaultRate(RateDistribution distribute);
        
		Rate& operator=(const Rate &p)
		{
        	miu_r = p.miu_r ;
        	sigma_r = p.sigma_r ;
			rates[0]= p.rates[0];
			rates[1]= p.rates[1];
			rates[2]= p.rates[2];
			rates[3]= p.rates[3];
        	//rates = p.rates ;
        	distribute = p.distribute ;
		}
    };
    
	class Param
    {
	public: 
		int m;  //movies.
        int x_m;  //chunks each movie.
        int n;
        int t;
        RequestGenConfig requestGenConfig;
        double miu_u;   //upload from peers, used in Peer.cc, in kbps
        double sigma_u;
		double initcache_uniform_exp;
        Rate rate;
		PopDistribution popDistribution;
		InitCacheConfig initCacheConfig;

        int x;

		Param(const Param &p);
		Param(){}
        Param(int m, int x_m, int n, int t, RequestGenConfig requestGenConfig, double miu_u, double sigma_u,
            Rate rate, PopDistribution popDistribution, InitCacheConfig initCacheConfig, double initcache_uniform_exp_p );
        Param & operator=(const Param &p);

    };

}

#endif
