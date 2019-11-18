#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
 
static int global_val = 0;
int main()
{
    int *p = (int*)malloc(sizeof(int));
    *p=0;  
    int m = 2;
	int res ;
	char buf[20]="\0";
	char bufs[8]="shenlei";
    pid_t pid ;
    int fd = open("mytest", O_RDWR | O_CREAT, 0666);
    if ((pid = fork()) < 0)
    {
       perror("fork error");
    }
    else {
        if (pid == 0)
    {
        res = read(fd,buf,20);
		printf("pdi: %d res: %d fd: %d buf: %s\n",getpid(),res,fd,buf);
        //sleep(1);
        lseek(fd, 0, SEEK_SET);    
        write(fd,bufs,strlen(bufs));
        global_val++;
        m++;
        (*p)++;
		close(fd);
    }
        else{
        sleep(1);
        lseek(fd, 0, SEEK_SET);
        res = read(fd,buf,20);
        printf("pdi: %d res: %d fd: %d buf: %s\n",getpid(),res,fd,buf);
		printf("%d %d %d\n",*p,m,global_val);
        }
    }
    return 0;
}
