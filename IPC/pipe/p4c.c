#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	perror("pipe");

	if(fork()==0)
	{
		char bf[5];
		read(p[0],bf,sizeof(bf));
		//bzero(bf,sizeof(bf));
		printf("bf = %s\n",bf);
	}

	else
	{
		char s[12];
		printf("enrer string\n");
		scanf("%s",s);

		write(p[1],s,sizeof(s));
		if(fork()==0)
		{
			char buf[7];
			bzero(buf,sizeof(buf));
			read(p[0],buf,sizeof(buf));
			printf("buf = %s\n",buf);
		}
	}
}
