all: p_program

p_program: Program.cc Exp.cc Movie.cc Param.cc Peer.cc RandomGen.cc Requests.cc Result.cc Segment.cc AllServerSchedule.cc NoPrefetchSchedule.cc LowerBound.cc PrioritySchedule.cc TestCase.cc
	g++ -g -rdynamic -o p_program Program.cc Exp.cc Movie.cc Param.cc Peer.cc RandomGen.cc Requests.cc Result.cc Segment.cc AllServerSchedule.cc NoPrefetchSchedule.cc LowerBound.cc PrioritySchedule.cc TestCase.cc

#factorial.o: factorial.cpp  
#	    g++ -c factorial.cpp  
		  
clean:  
	    rm -rf p_program
