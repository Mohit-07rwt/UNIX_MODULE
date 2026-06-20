#include"header.h"
void convert(char *p)
{
	for(int i=0;p[i];i++)
		if(p[i]>='a' && p[i]<='z')
			p[i]=p[i]-32;
}

void main()
{
	int p[2];
	int r[2];

	pipe(r);
	pipe(p);
	//perror("pipe");
//	printf("Read end = %d\n",p[0]);
//	printf("Write end =%d\n",p[1]);

	if(fork()==0)
	{
		char s[20];
		printf("in child before read =%d....\n",getpid());
		read(p[0],s,sizeof(s));

//		printf("original data =%s  \n",s);
		convert(s);
		write(r[1],s,strlen(s)+1);
	}
	else
	{
		char s[20];
		printf("enter the string....: \n");
		scanf("%s",s);
		write(p[1],s,sizeof(strlen(s)+1));
		//sleep(1);

		read(r[0],s,sizeof(s));
		printf("converted string.....%s\n",s);
	}
}
