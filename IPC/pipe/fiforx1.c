#include"header.h"
void main()
{
	mkfifo("f1",0664);
	int fd=open("f1",O_RDONLY);
//	int fd=open("f1",O_RDWR);

	printf("in rx side...\n");
	
	char s[20];

//while(1)
//{
	int n=read(fd,s,sizeof(s)-1);
	s[n]='\0';
	printf("%s",s);

//	for(int i=0;s[i];i++)
	//{
	//	if(s[i]>='a' && s[i]<='z')
	//		s[i]=s[i]-32;
	//}
	//write(fd,s,sizeof(s));
//}

}
