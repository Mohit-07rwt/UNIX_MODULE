#include"header.h"
void main()
{
	signal(1,SIG_IGN);
	printf("hello pid=%d\n",getpid());
	while(1);
}
