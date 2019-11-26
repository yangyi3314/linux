#include"my.h"
int main()
{
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[10];
	memset(buf,0,sizeof(buf));
	if (pipe(pipefd) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r = fork();
	if(r < 0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if (r == 0)
	{
 
		close(pipefd[1]);
		
		if((r_num=read(pipefd[0],buf,100))>0)
			printf("child read from pipe:%s,total=%d\n",buf,r_num);
		close(pipefd[0]);
		exit(0);
	}
	else
	{
 
		close(pipefd[0]);
		if(write(pipefd[1],"1234567890",10)!=-1)
			printf("parent write ok.\n");
		close(pipefd[1]);
		exit(0);
	}
	return 0;
}

