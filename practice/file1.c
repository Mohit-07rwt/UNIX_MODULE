#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("./a.out usage");
		return;
	}
	char s[200];
	printf("inside parent\n");
	scanf(" %[^\n]", s);
	int fd=open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0664);
	write(fd,s,strlen(s));
	
	if(fork()==0)
	{
		char s[200];
		printf("enter string inside child\n");
		scanf(" %[^\n]", s);

		int fd=open(argv[1],O_WRONLY|O_CREAT|O_APPEND,0664);

		write(fd,s,strlen(s));
		write(fd,"\n",1);
		close(fd);
		exit(0);
	}
	else
	{
		wait(0);
		lseek(fd, 0, SEEK_SET);
		printf("file content = ");	
		while(read(fd,s,sizeof(s))>0)
		printf("%s",s);
		close(fd);
	}
}
