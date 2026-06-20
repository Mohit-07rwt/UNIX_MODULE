#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	perror("pipe");
	printf("Read end = %d\n",p[0]);
	printf("Write end =%d\n",p[1]);

	if(fork()==0)
	{
		int num;
		printf("in child before read....\n");
		read(p[0],&num,sizeof(num));

		printf("original data =%d\n",num);

		int new=0;
		for(;num;num=num/10)
			new=(new*10)+num%10;
		printf("reverse of original data = %d",new);
	}
	else
	{
		int num;
		printf("enter the number....: \n");
		scanf("%d",&num);
		write(p[1],&num,sizeof(num));
	}
}
