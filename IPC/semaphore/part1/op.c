#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage ./op opval (0,>0,<0)\n");
		printf("ex:./op 2\n");
	}
	int id=semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return;
	}

	printf("id=%d\n",id);
	
	struct sembuf v;
	v.sem_num=2;
	v.sem_op=atoi(argv[1]);
	//v.sem_flg=SEM_UNDO;
	
	v.sem_flg=0;
	printf("before....\n");
	semop(id,&v,1);
	printf("after....\n");
	sleep(30);
	printf("done...\n");
}
