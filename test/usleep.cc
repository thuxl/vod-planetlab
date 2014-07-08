 #include<stdio.h>
 #include<unistd.h>
 int main()
{
	int a, i;
	a=1;
	for (i = 0; i< 5; i++) {
		printf("sleep [%d]s  ", a);
		sleep(a);        /* VC 使用Sleep*/
		printf("world\n"); 
	}
	double b=1.000500;

	for (i = 0; i< 5; i++) {
		printf("usleep [%d]us  ",(int)(b* 1000000));
		usleep((int)(b*1000000));        /* VC 使用Sleep*/
		printf("world\n"); 
	}

	
	return 1;
}
