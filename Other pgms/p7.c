#include<stdio.h>
#include<errno.h>
void main()
{
	int e1=ENODEV;
	e1=15;
	printf("%d\n",e1);
	
	int e2=ENOENT;
	e2=16;
	printf("%d",e2);

}
