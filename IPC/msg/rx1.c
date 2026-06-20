#include"header.h"
struct msgbuf
{
	long int mtype;
	char s[20];
};

void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./rx mtype(0,>0,<0)\n");
		printf("ex:./rx  2 \n");
		return;
	}

	int id=msgget(4,IPC_CREAT|0664);
	if(id<0)
	{
		perror("msgget");
		return;
	}
	printf("id=%d \n",id);
struct msgbuf v;
	printf("Before....\n");
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	printf("after data =%s \n",v.s);
}
