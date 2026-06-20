#include"header.h"
void f1()
{
	printf("Inside child");
	char c;
	FILE *fp=fopen("child.txt","w");
	for(c='a';c<='z';c++)
	{
		fprintf(fp,"%c\n",c);
	}			
}

void f2()
{
	printf("Inside parent");
	char c;
	FILE *fp=fopen("parent.txt","w");
	for(c='A';c<='Z';c++)
	{
		fprintf(fp,"%c\n",c);
	}		
}

int main()
{
	if(fork()==0)
	{
		f1();
	}
	else
	{
		f2();
	}

}
