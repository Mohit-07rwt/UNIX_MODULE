#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage :./raise signum pid\n");
		return;
	}	
	raise(atoi(argv[1]));
	perror("terminated");
}
