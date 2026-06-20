#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage ./set sema\n");
		printf("ex:./set 2 5\n");
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
	printf("id=%d\n",id);	
	semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
		perror("semctl");
}
