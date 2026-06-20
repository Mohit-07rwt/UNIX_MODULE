#include"header.h"
void main()
{
	int fd=dup(0);
	printf("%d\n",fd);
	//int fd=dup2(1,9);
	write(fd,"hello\n",6);

}
