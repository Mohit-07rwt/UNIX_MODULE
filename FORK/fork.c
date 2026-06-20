#include"header.h"
void main()
{
	int i=10;
//	if(vfork()==0)
	if(fork()==0)
	{
		i=200;
		printf("child i= %d\n",i);
		exit(0);
	}
	else
	{
		printf("parent i = %d\n",i);
	}
}
