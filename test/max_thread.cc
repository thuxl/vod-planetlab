#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>


void* func(void* ptr)
{
	static int count = 1;
	printf("cread thread, num %d\n", count);
	count++;
	pthread_detach(pthread_self());

	pthread_exit(NULL);
}


int main()
{
	int err;
	pthread_t tid;
	int ret ,stacksize = 30720; /*thread 堆栈设置为20K，stacksize以字节为单位。*/
	//int ret ,stacksize = 20480; /*thread 堆栈设置为20K，stacksize以字节为单位。*/
	pthread_attr_t attr;


	while (1){
		ret = pthread_attr_init(&attr); /*初始化线程属性*/
		if (ret != 0){
			printf("1 ret [%d]\n", ret);
			return -1;
		}

		ret = pthread_attr_setstacksize(&attr, stacksize);
		if(ret != 0){
			printf("2 ret [%d]\n", ret);
			return -1;
		}

		err = pthread_create(&tid, &attr, func, NULL);
		//err = pthread_create(&tid, NULL, func, NULL);

		ret = pthread_attr_destroy(&attr); /*不再使用线程属性，将其销毁*/
		if(ret != 0){
			printf("3 ret [%d]\n", ret);
			return -1;
		}
		
		
		if (err==EAGAIN ){
			printf("creat thread err [%d]\n", err);
			printf("Insufficient  resources  to  create  another thread,\n\t ");
			printf("or a system-imposed limit on the number of threads was encountered.\n");
			printf("The latter case may occur in two ways:\n");
			printf("\tthe RLIMIT_NPROC soft resource limit (set via setrlimit(2)), which limits  the  number  of\n");
			printf("\tprocess  for  a  real  user  ID,  was  reached;  or  the  kernel's system-wide limit on the number of threads, /proc/sys/ker‐nel/threads-max, was reached.\n");
			break;
		}
		else if (err==EINVAL ){
			printf("creat thread err [%d]\n", err);
			printf("Invalid settings in attr.\n");
			break;
		}
		else if (err==EPERM  ){
			printf("creat thread err [%d]\n", err);
			printf("No permission to set the scheduling policy and parameters specified in attr.\n");
			break;
		}
		else if (err!=0){
			printf("creat thread err [%d]\n", err);
			printf("unkown err.\n");
			break;
		}
	}

	return 1;
}

