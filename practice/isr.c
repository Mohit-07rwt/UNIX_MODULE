//Program catches SIGINT. First Ctrl+C prints warning. Second Ctrl+C exits
#include"header.h"
void my_isr(int n)
{
	static int count;
	if(count==0 && n==2)
		printf("WARNING!!\n");

	else
	{
		signal(n,SIG_DFL);
		raise(n);
	}
	count++;
}

void main()
{
	printf("hello in main : %d\n",getpid());
	signal(2,my_isr);
	while(1);
}
