/*Parent sends a string to child using pipe. Child converts it to uppercase and sends back. Parent prints the result.*/
#include"header.h"
void main(int argc,char **argv)
{
	int p[2],q[2];
	pipe(p);
	pipe(q);
	perror("pipe");
	char s[200];
	printf("enter string");
	scanf("%[^\n]",s);
	write(p[1],s,strlen(s));
	
	if(fork()==0)
	{
		char s[200];
		read(p[0],s,sizeof(s));
		
		printf("in child \noriginal string = %s",s);
		for(int i=0;s[i];i++)
		{
			s[i]=s[i]-32;
		}

		write(q[1],s,strlen(s)+1);
		exit(0);
	}

	else
	{
		wait(0);
		char s[200];
		read(q[0],s,sizeof(s));
		printf("\nin parent \nupdated string = %s",s);
	}
}
