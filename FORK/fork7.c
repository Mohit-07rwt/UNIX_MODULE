#include"header.h"
void main()
{
	if(fork()==0)
	{
		printf("child1 pid=%d	ppid=%d\n",getpid(),getppid());
		
		FILE *fp=fopen("child1.txt","w");
		if(fp==0)
		{
			printf("child1.txt not found!!\n");
			return;
		}
	
		int a1[50];
		srand(getpid());	
	
		for(int i=0;i<50;i++)
		{
			a1[i]=rand()%51+50;
			fprintf(fp,"%d\n",a1[i]);
		}	
		fclose(fp);
	}

	else
	{		
		printf("parent1 pid=%d\n",getpid());
		if(fork()==0)
		{
			printf("child2 pid=%d	ppid=%d\n",getpid(),getppid());
			FILE *fp1=fopen("child2.txt","w");
		if(fp1==0)
		{
			return;
			printf("child2.txt not found!!\n");
		}
			int a2[50];
		
			srand(getpid());	
			for(int i=0;i<50;i++)
			{
				a2[i]=rand()%101+100;
				fprintf(fp1,"%d\n",a2[i]);
			}
			fclose(fp1);
		}
		else
		{
			printf("parent2 pid=%d\n",getpid());
			
			if(fork()==0)
			{
				srand(getpid());	
				printf("child3 pid=%d	ppid=%d\n",getpid(),getppid());
			
				FILE *fp2=fopen("child3.txt","w");
			
				if(fp2==0)
				{
					return;
					printf("child3.txt not found!!\n");
				}
				int a3[50];
		
				for(int i=0;i<50;i++)
				{
					a3[i]=rand()%201+200;
					fprintf(fp2,"%d\n",a3[i]);
				}
				fclose(fp2);
			}
			else
				printf("parent3 pid=%d\n",getpid());
		}
	}
		while(1);
}
