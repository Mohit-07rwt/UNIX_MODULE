#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage :./mykill signum pid\n");
		return;
	}	
	kill(atoi(argv[2]),atoi(argv[1]));
	perror("kill");
}
