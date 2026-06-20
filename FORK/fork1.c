#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	printf("hello pid = %d\n",getpid());
	fork();
	printf("hai pid =%d\n",getpid());
	while(1);
}
