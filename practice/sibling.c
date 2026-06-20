//Parent creates two children. First sends number through pipe. Second prints square.
#include"header.h"
void main()
{
	printf("in main....\n");
	int p[2],num;
	pipe(p);

	if(fork()==0)
	{
		int num;
		printf("enter num \n ");
		scanf("%d",&num);
		write(p[1],&num,sizeof(num));
	}

	else
	{	
		wait(0);
		if(fork()==0)
		{
			int num;
			read(p[0],&num,sizeof(num));
			printf("sq = %d\n",num*num);
			exit(0);
		}

		close(p[0]);
        	close(p[1]);
		wait(0);
	}
}
