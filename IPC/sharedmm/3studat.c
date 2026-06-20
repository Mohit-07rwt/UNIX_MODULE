#include"header.h"
struct stu
{
	int rollnum;
	char name[20];
	float marks;
};
void main()
{

	int id=shmget(4,50,IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return;
	}

printf("id=%d\n",id);

struct stu *p=shmat(id,0,0);
perror("shmat");

printf("enter rollnum name marks  of 3 student\n");
for(int i=0;i<3;i++)
{
	//scanf("%d%s%f",&p[i].rollnum,p[i].name,&p[i].marks);
	scanf("%d%s%f",&p->rollnum,p->name,&p->marks);
	p++;	
}
}
