#include"header.h"
void main()
{
	if(fork()==0)
	{
		printf("child1 pid=%d	ppid=%d\n",getpid(),getppid());
	}
	else
	{		
		printf("parent pid=%d\n",getpid());
		if(fork()==0)
		{
			printf("child2 pid=%d	ppid=%d\n",getpid(),getppid());
		}
		else
		{
			printf("parent pid=%d\n",getpid());
			if(fork()==0)
			{
				printf("child3 pid=%d	ppid=%d\n",getpid(),getppid());
			}
			else
				printf("parent pid=%d\n",getpid());
		}
	}
		while(1);
}

