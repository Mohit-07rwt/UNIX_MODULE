#include"header.h"
void f1()
{
//	while(1)
	printf("inside child\n");
	sleep(10);
}

void f2()
{
//	while(1)
	printf("\t\t\tinside parent\n");
	sleep(10);
}

int main()
{
	if(fork()==0)
		f1();
	else
		f2();
}
