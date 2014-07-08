#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//g++ threadmember.cc -o pthreadmember -lpthread
//
class classa{
public:
	static int a;
	static int incre;
	classa(){}

	void run1();
	static void* change(void *ptr);
	
};

int classa::a=0;
int classa::incre=20;
int b=0;
static int c=0;

void* classa::change(void *ptr)
{
	sleep(1); classa::a=3; b=3; c=3;
	printf("in pthread, wait 1s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	//exit(0);
	sleep(2); classa::a=5; b=5; c=5;
	printf("in pthread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2); classa::a=7; b=7; c=7;
	printf("in pthread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2); classa::a=incre; b=incre; c=incre;
	printf("in pthread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	
	
}

void classa::run1()
{
	classa::a=1;
	b=1;
	c=1;

	pthread_t pid;
	pthread_create(&pid, NULL, change, NULL);
	
	printf("in main thread, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in main thread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in main thread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in main thread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in main thread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in main thread, wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);

}


int main()
{
	classa test;

	test.run1();

	return 1;
}

