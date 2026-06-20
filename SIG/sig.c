#include"header.h"
void my_isr(int n)
{
	printf("in isr n=%d\n",getpid());
	//wait(0);
	waitpid(-1,0,WUNTRACED|WCONTINUED);
}

void main()
{
	if(fork()==0)
	{
		printf("in c pid=%d\n",getpid());
		while(1);
	}
	else
	{
		printf("in parent pid=%d\n",getpid());
		signal(17,my_isr);
		while(1);
	}
}
