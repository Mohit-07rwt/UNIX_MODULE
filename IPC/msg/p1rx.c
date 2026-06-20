#include"header.h"
struct stu
{
	int rollnum;
	char name[20];
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
		printf("usage!!\n");
		return;
	}	
	
	int fd=msgget(4,IPC_CREAT|0664);	
	if(fd<0)
	{
		perror("msgget");
		return;
	}
	
	struct msgbuf msg;

	msgrcv(fd,&msg,sizeof(msg),atoi(argv[1]),0);
	perror("msgrcv");
	printf("rollnum = %d\n",msg.s.rollnum);
	printf("name = %s\n",msg.s.name);
}
