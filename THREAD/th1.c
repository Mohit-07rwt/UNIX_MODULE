#include"header.h"
void * thread_1(void *p)
{
	while(1)
		printf("\t\t\tin thread_1 pid=%d	tid=%ld\n",getpid(),pthread_self());

}

void main()
{
	pthread_t t1;
	pthread_create(&t1,0,thread_1,0);

while(1)
printf("\t\t\tin main pid=%d	tid=%ld\n",getpid(),pthread_self());

}
