#include"header.h"
void * thread_1(void *p)
{
	printf("in thread_1 %s\n\n",(char *)p);
	sleep(3);
	printf("in thread_1 after sleep\n");
	//pthread_exit("bye");
	//pthread_exit();
}

void main()
{
	pthread_t t1;
	pthread_create(&t1,0,thread_1,"hello");

	void *p;
	pthread_join(t1,&p);

	printf("after pthread_join %s\n\n",(char *)p);
	
}
