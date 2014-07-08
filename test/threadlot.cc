#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

//g++ threadlot.cc -o pthreadlot -lpthread
//
class classa{
public:
	static int a;
	static int incre;
	classa(){}

	void run1();
	static void* change1(void *ptr);
	static void* change2(void *ptr);
	
};

int classa::a=0;
int classa::incre=20;
int b=0;
static int c=0;

void* classa::change1(void *ptr)
{
	
	int i = *(int*)ptr;

	if (i == 3)
		pthread_exit(NULL);
	
	time_t start = time(NULL);
	sleep(5);
	time_t end = time(NULL);
	//double pass= double (clock() - start) / CLOCKS_PER_SEC;
	printf("in pthread 1, i=[%d] , pass=[%ld]\n", i, end-start );
	pthread_exit(NULL);
	
}

void* classa::change2(void *ptr)
{
	printf("in pthread 2, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	
}


void classa::run1()
{
	classa::a=1;
	b=1;
	c=1;


	pthread_t pid[5];
	for (int i=0; i<5; i++){
		
		pthread_create(&pid[i], NULL, change1, &i);
		sleep(1);
		//pthread_join(pid,NULL);
	}


	for (int i=0; i<5;i++)
		pthread_join(pid[i],NULL);
	
	//sleep(1);
	//pthread_join(pid[0],NULL);
	//pthread_join(pid[1],NULL);
	//pthread_join(pid[2],NULL);
	//pthread_join(pid[3],NULL);
	//pthread_join(pid[4],NULL);

	printf("in main thread, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	

}


int main()
{
	classa test;

	test.run1();

	return 1;
}

