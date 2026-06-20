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
	if(argc!=5)
	{
		printf("usage:./tx mtype rollnum name marks\n");
		printf("ex:./tx 1 10 rohan 50.0\n");
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

	v.mtype=atoi(argv[1]);
	v.s.rollnum=atoi(argv[2]);
	strcpy(v.s.name,argv[3]);
	v.s.marks=atof(argv[4]);

	msgsnd(id,&v,sizeof(v.s),0);
	perror("msgsnd");
}
