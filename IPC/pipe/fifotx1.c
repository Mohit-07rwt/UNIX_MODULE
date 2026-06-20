#include"header.h"
void main()
{
	int r=mkfifo("f1",0664);
	printf("before\n");

	int fd=open("f1",O_WRONLY);
	//int fd=open("f1",O_RDWR);
	printf("After\n");

	char s[20];
	printf("enter the data\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);

	//char buf[2000];
	//read(fd,buf,sizeof(buf));
	//printf("%s",buf);
}
