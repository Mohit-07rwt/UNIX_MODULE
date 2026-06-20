#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int a[5],i,n,sum=0;
	FILE *fp = fopen("data.txt","r");
	srand(getpid());
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%d",&n);
		sum+=n;
		if(i==4)
			printf("\n");
	}

	printf("%d",sum);
	fclose(fp);
	
}
