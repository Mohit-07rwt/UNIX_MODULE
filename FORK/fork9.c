#include"header.h"
void main()
{
	if(fork()==0)
	{
		printf("In c before sleep pid=%d  ppid=%d\n",getpid(),getppid());
		sleep(2);
		FILE *fp=fopen("DATA.txt","w");
		if(fp==0)
		{
			printf("file not present");
			return;
		}
		char i;
		for(i='a';i<'z';i++)
		{
			fprintf(fp,"%c\n",i);
		}
		fprintf(fp,"%s","\n........child written successfully......\n\n");
		fclose(fp);
		exit(1);
	}

	else
	{
		int r,s;
		//r=wait(&s);
		wait(&s);
		printf("in p before wait pid=%d\n",getpid());
		sleep(2);
		if(WIFEXITED(s))
		{
			printf("child is terminated normally / parent block %d\n",WEXITSTATUS(s));
			FILE *f=fopen("DATA.txt","a");
			if(f==0)
			{
				printf("file not present");
				return;
			}

			char ch;
			for(ch='A';ch<'Z';ch++)
			{
				fprintf(f,"%c\n",ch);
			}
			fprintf(f,"%s","\n........parent written successfully......\n\n");
			fclose(f);
		}
	}
}
