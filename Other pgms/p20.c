#include<stdio.h>
#include"header.h"
void main(int argc,char **argv,char **env)
{
	int i,c=0;
	for(i=0;env[i];i++)
	{
		printf("%s\n\n",env[i]);
		c++;
		sleep(1);
	}	

	printf("\nDONE......\n");
	printf("total = %d",c);
}
