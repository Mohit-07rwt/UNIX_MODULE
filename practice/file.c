//Copy contents from source.txt to dest.txt using system calls open, read, write.
#include"header.h"
void main()
{
	int fd=open("src",O_WRONLY|O_CREAT|O_TRUNC,0664);
	char s[240];
	printf("enter string");
	scanf(" %[^\n]", s);
	write(fd,s,strlen(s));

	close(fd);	

	fd=open("src",O_RDONLY);
	int ff=open("dest",O_WRONLY|O_CREAT|O_TRUNC,0664);
	char buf[1000];
	
int n;
	n=read(fd,buf,sizeof(buf));	
	write(ff,buf,n);

	close(fd);
	close(ff);
	printf("copied");
}
