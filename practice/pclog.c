#include"header.h"
int fd;
void my_isr(int n)
{
	printf("in my_isr\n");
	close(fd);
	exit(0);
}

void my_handler(int n)
{
	printf("10 sec completed\n");
	close(fd);
	exit(0);
}
		
void main()
{
	int p[2],pid;
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		signal(SIGTERM,my_isr);
		close(p[1]);	
		char buf[2000];
		fd=open("log",O_WRONLY|O_CREAT|O_TRUNC,0664);
		while(1)
		{
			int n=read(p[0],buf,sizeof(buf));
			if(n>0)
			{
				write(fd,buf,n);
				write(fd,"\n",1);

			}
			else
				break;
		}
		close(p[0]);
		exit(0);
	}
	else
	{
		close(p[0]);
		printf("in main\n");
		char s[2000];
	
		signal(SIGALRM,my_handler);
		alarm(10);
		while(1)
		{
			printf("enter data\n");
			scanf(" %[^\n]", s);
			write(p[1],s,strlen(s));
		}
		printf("After 10 seconds...\n");
		kill(pid,SIGTERM);
		close(p[1]);
		wait(0);
	}
}
