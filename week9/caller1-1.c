#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{ execl("/home/yangyi/Desktop/linux/weeks-nine/test1-1","123","456",NULL);
    int ret;
    printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
   
	printf("after calling");
    sleep(100);
    return 0;
}