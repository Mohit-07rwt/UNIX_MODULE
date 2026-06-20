#include"header.h"
void my_isr(int n)
{
	printf("in isr 	n= %d	pid=%d\n",n,getpid());
	sleep(5);
	printf("in isr after sleep.......\n");
}

void main()
{
		printf("hello pid=%d\n",getpid());
		struct sigaction v;
		v.sa_handler=my_isr;
		//sigemptyset(&v.sa_mask);
		sigfillset(&v.sa_mask);
		//v.sa_flags=0;
		//v.sa_flags=SA_NOCLDSTOP;
		v.sa_flags=SA_NOCLDWAIT;
		//v.sa_flags=SA_NOCLDWAIT;	
		//v.sa_flags=SA_RESETHAND;
		sigaction(2,&v,0);
		printf("hai\n");
		while(1);
}
