//Parent reads input, sends to child via pipe. Child writes to file. Parent sends signal to terminate.
#include"header.h"
void my_isr(int n)
{
	printf("child writes successfully");
	exit(0);
}

void main()
{
	int p[2],r;
	pipe(p);
	char buf[2000];
	printf("enter data  \n");
	scanf("%[^\n]",buf);
	
	write(p[1],buf,strlen(buf)+1);
	
	if(r=fork())
	{
		signal(10,my_isr);
		pause();
		printf("in parent \n");
	}

	else
	{
		char buf[2000];
		int fd=open("child",O_WRONLY|O_CREAT|O_TRUNC,0664);
		int n=read(p[0],buf,sizeof(buf));
		printf("buf  = =%s",buf);
			
		write(fd,buf,n);
		kill(getppid(),10);

	}
}
