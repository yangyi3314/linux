#include "my.h"
int main()
{
	int pipefd[2];
	int pipefd2[2];
	int a[16384];
	int sum=0;
	int i;
	int stat=0;
	pid_t id2;
	pid_t id3;
	srand(time(NULL));
	if (pipe(pipefd) < 0)
	{
		perror("pipe\n");
		return 1;
	}
	if (pipe(pipefd2) < 0)
	{
		perror("pipe2\n");
		return 1;
	}
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 2;
	}
	else if (id == 0)
	{
 
		close(pipefd[0]);
		
		for(i=0;i<16384;i++){
			a[i]=rand()%100;
			write(pipefd[1],&a[i],sizeof(int));
		}
		close(pipefd[1]);
		exit(0);
		
	}
	else
	{
		id2 = fork();
		if(id2 < 0)
		{
			perror("fork2");
			return 2;
		}
		else if(id2==0){
			for(i=0;i<16384;i++){
				read(pipefd[0],&a[i],sizeof(int));
				printf("%d\n",a[i]);
			}
			for(i=0;i<16384;i++){
				write(pipefd2[1],&a[i],sizeof(int));
			}
			exit(0);
		}else{
			sleep(1);
			id3 = fork();
			if(id3 < 0)
			{
				perror("fork3");
				return 2;
			}
			else if(id3==0){
				close(pipefd[0]);
				close(pipefd[1]);
				close(pipefd2[1]);
				for(i=0;i<16384;i++){
					read(pipefd2[0],&a[i],sizeof(int));
					sum+=a[i];
				}
				printf("sum = %d\n",sum);
				close(pipefd2[0]);
				exit(0);
			}else{
				sleep(1);
				exit(0);
			}
		}
		
	}
	return 0;
}

