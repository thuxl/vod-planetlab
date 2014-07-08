#ifndef PEER_H
#define PEER_H

#include <stdio.h>
#include <stdlib.h>

#include <list>
using namespace std;

#include "Param.h"
#include "Movie.h"
#include "RandomGen.h"


namespace bandwidth
{
	class Param;
	class Movie;
	class RandomGen;

    class Peer
    {
	public:
		int peeridx;
        double upBand;
        list<int> initCache;
        int* requests;
		~Peer();

        static Peer* GenPeers(Param &param, Movie* movies, RandomGen &randomGen);

	private:
		void genPeer(Param &param, Movie* movies, int peeridx, RandomGen &randomGen);

        void genRequests(Param &param, Movie* movies, RandomGen &randomGen, int peeridx);

        static list<int> genInitCache(Param &param);


	public:
		
		static InitCacheConfig DefaultInitCacheConfig(InitCacheConfig::ConfigType type);
		static RequestGenConfig DefaultInitRequestGenConfig(double p_r);

    };
    
	
	
}

#endif
