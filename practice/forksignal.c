//Child runs infinite loop printing message. Parent waits 5 seconds and sends signal. Child handles signal and exits.
#include"header.h"
void my_isr(int n)
{
	printf("in myisr");
	exit(0);
}
void main()
{
	int r;
	if(r=fork())
	{
		printf("in parent =%d",getpid());
		sleep(5);
		kill(r,10);
	}
	else
	{
		signal(10,my_isr);
		while(1)
		{
			printf("in child\n");
			sleep(1);
		}
	}
}
