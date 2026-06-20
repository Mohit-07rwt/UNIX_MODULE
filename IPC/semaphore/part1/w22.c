#include"header.h"
void main()
{
	int id=semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return;
	}
	int fd=open("DATA",O_WRONLY|O_APPEND|O_CREAT,0664);
	if(fd<0)
	{
		return;
	}
	struct sembuf v;
	v.sem_num=3;
	v.sem_op=0;
	v.sem_flg=0;

	printf("before....\n");
	for(char ch='A';ch<='Z';ch++)
	{
		semop(id,&v,1);
		semctl(id,2,SETVAL,1);
		write(fd,&ch,1);
		semctl(id,2,SETVAL,0);
		semctl(id,3,SETVAL,1);
	}
	printf("done....\n");
}
