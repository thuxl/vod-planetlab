#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


class classa{
public:
	static int a;
	classa(){};

	void run1();
};

int classa::a=0;
int b=0;
static int c=0;

void classa::run1()
{
	classa::a=1;
	b=1;
	c=1;

	int pid = fork();
	if (pid==0)//child
	{
		sleep(1);
		classa::a=3;
		b=3;
		c=3;
		printf("in child, wait 1s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
		exit(0);
	}
	printf("in father, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);
	sleep(2);
	printf("in father,wait 2s, a=[%d] b=[%d] c=[%d]\n", classa::a, b, c);

}


int main()
{
	classa test;

	test.run1();

	return 1;
}

