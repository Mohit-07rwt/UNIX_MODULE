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
	if(argc!=4)
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
	msg.mtype=atoi(argv[1]);
	msg.s.rollnum=atoi(argv[2]);
	strcpy(msg.s.name,argv[3]);

	msgsnd(fd,&msg,sizeof(msg),0);
	perror("msgsnd");
}
