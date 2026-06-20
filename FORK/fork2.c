#include"header.h"
void my_isr(int n)
{
	printf("signal recieved\n");
}
void main()
{
	int r;
	printf("hello ppid=%d\n",getppid());
	if((r=fork()))
	{
		FILE *fp=fopen("alpha.txt","w");
		fprintf(fp,"%s","----------IN PARENT---------\n");
		for(char i='A';i<='Z';i++)
		{
			fprintf(fp,"%c\n",i);
			printf("parent is writing %c\n",i);
		}
		fclose(fp);
		kill(r,10);
	}
	else
	{
		signal(10,my_isr);
		pause();
		FILE *fp=fopen("alpha.txt","a");
		fprintf(fp,"%s","\n--------------IN CHILD-------------\n");
		for(char ch='a';ch<='z';ch++)
		{
			fprintf(fp,"%c\n",ch);
			printf("child is writing %c\n",ch);
		}
		fclose(fp);
	}	
}
