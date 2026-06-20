#include"header.h"
void main()
{
	int id=msgget(3,IPC_CREAT|0664);
//	int id=msgget(IPC_PRIVATE,IPC_CREAT|0664);
//	int id=msgget(5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("msgget");
		return;
	}
//	printf("id=%d\n",id1);
//	printf("id=%d\n",id2);
	printf("id=%d  \n",id);
}
