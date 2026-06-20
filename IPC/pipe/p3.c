#include"header.h"
typedef struct st
{
	int n1,n2;
	char op;
}ST;

void main(int argc,char **argv)
{
	int p[2];
	int r[2];
	pipe(p);
	pipe(r);

	if(fork()==0)
	{
		ST v1;
		printf("in server .....\n");
		read(p[0],&v1,sizeof(v1));	
		int sum=0;
		switch(v1.op)
		{
			case '+':
				sum=v1.n1+v1.n2;	
				break;
			case '-':
				sum=v1.n1-v1.n2;	
				break;
			case '*':
				sum=v1.n1*v1.n2;	
				break;
			case '/':
				sum=v1.n1/v1.n2;	
				break;
			default:
				printf("INVALID......\n");
		}
		write(r[1],&sum,sizeof(sum));	
	}	
	else
	{
		if(argc!=4)
		{
			printf("a.out usage,........\n");
			return;
		}
		ST v;
		int n1,n2;
		v.n1=atoi(argv[1]);
		v.n2=atoi(argv[3]);
		v.op=argv[2][0];
		write(p[1],&v,sizeof(v));	

		int sum=0;
		read(r[0],&sum,sizeof(sum));	
		printf("sum = %d\n",sum);
	}
}
