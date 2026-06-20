#include"header.h"
void main()
{
	int p[2];
	//pipe(p);
	pipe2(p,O_NONBLOCK);
	char ch='a';
	int c=0;

	while(write(p[1],&ch,1)!=-1)
		c++;
		printf("c= %d\n",c);

printf("done.....\n");
}
