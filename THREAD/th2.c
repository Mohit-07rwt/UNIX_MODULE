#include"header.h"
void *thread_1(void *p)
{
		int sum=0;	
		//printf("in thread 1   %d\n",(int *)p);
		printf("\t\t\tin thread pid=%d	tid=%ld\n",getpid(),pthread_self());
		for(int i=0;i<5;i++)
		{
			sum+=*((int *)p+i);
			printf("%d ",*((int *)p+i));
		}
		printf("sum = %d",sum);

	//	exit(0);
}

void main(int argc,char **argv)
{
	if(argc!=6)
	{
		printf("INVALID\n");
		return;
	}
	int a[5],i;
	for(i=0;i<5;i++)
	{
		a[i]=atoi(argv[i+1]);
	}

	pthread_t t1;
	pthread_create(&t1,0,thread_1,a);
printf("\t\t\tin main pid=%d	tid=%ld\n",getpid(),pthread_self());
	pthread_exit(0);
//while(1);
}
