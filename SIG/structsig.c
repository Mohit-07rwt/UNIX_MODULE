#include"header.h"
void my_isr(int n)
{
	printf("in isr n=%d	 pid=%d\n",n,getpid());
}
void main()
{
	printf("hello	pid=%d\n",getpid());
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=0;

	sigaction(2,&v,0);

	printf("hai...\n");
	while(1);
}
