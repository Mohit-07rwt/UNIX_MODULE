#include"header.h"
void main()
{
	int p1[2];
	pipe(p1);	
	if(fork()==0)
	{
		char s[5];
		bzero(s,sizeof(s));
		read(p1[0],s,sizeof(s));
		printf("child 1= %s\n",s);
	}
	else
	{
		char s[12]="abcdefghij";
		write(p1[1],s,sizeof(s));		

		if(fork()==0)
		{
			char s[6];
			bzero(s,sizeof(s));
			read(p1[0],s,sizeof(s));
			printf("child 2 =%s\n",s);
		}
	}
}
