#include"header.h"
void my_isr(int n)
{
	printf("in isr 	n= %d	pid=%d\n",n,getpid());
	sleep(10);
	printf("in isr after sleep.......\n");
}

void main()
{
/*	if(fork()==0)
	{
		printf("in child pid=%d\n",getpid());
		while(1);
	}*/
	else
	{
		printf("in parent pid=%d\n",getpid());
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=0;
		//v.sa_flags=SA_NOCLDSTOP;
		//v.sa_flags=SA_NOCLDWAIT;
		//v.sa_flags=SA_NODEFER;
		sigaction(17,&v,0);
		
		while(1);
	}
}
