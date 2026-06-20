#include"header.h"

struct stu
{
	int rollnum;
	char name[20];
	float marks;
};

struct msgbuf
{
	long int mtype;
	struct stu s;
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
	msgrcv(id,&v,sizeof(v.s),atoi(argv[1]),0);
//	printf("after data =%s \n",v.s);
	printf("after data =%d \n",v.s.rollnum);
	printf("after data =%s \n",v.s.name);
	printf("after data =%.2f \n",v.s.marks);
}
