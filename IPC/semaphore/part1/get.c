#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage ./get sema\n");
		printf("ex:./get 2\n");
	}
	int id=semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	int ret=semctl(id,atoi(argv[1]),GETVAL);
	if(ret<0)
	{
		perror("semctl");
		return;
	}
	printf("ret=%d\n",ret);	
}
