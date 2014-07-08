#include <stdio.h>
#include <stdlib.h>

//g++ -D PEER_ID=5 -o pmacro macro.cc 
int main()
{
#ifdef PEER_ID
	printf("peer id=[%d]\n", PEER_ID);
#else
	printf("no def peer id\n");
#endif


	return 1;
}
