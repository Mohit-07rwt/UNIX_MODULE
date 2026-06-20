#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		//ps -e
		close(p[0]);
		dup2(p[1],1);
		execlp("ps","ps","-e",NULL);
	}
	else
	{
		if(fork()==0)
		{			
			close(p[1]);
			dup2(p[0],0);
			execlp("grep","grep","pts/0",NULL);
		}
		else
		{
			close(p[0]);
			close(p[1]);
			wait(0);
			wait(0);
		}
	}
}
