#include"header.h"
void main()
{

	int id=shmget(4,50,IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return;
	}

printf("id=%d\n",id);

char *p=shmat(id,0,0);
perror("shmat");
printf("recieved data\n");
for(int i=0;i<50;i=i+10)
{
	printf("%s\n",p+i);
}
}
