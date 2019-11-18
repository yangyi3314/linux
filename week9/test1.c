#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int x=100;
int main()
{
    int y=0;
    static int w=33;
    printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
    printf("test1:address x=%ld,y=%ld,w=%ld\n",&x,&y,&w);
    sleep(100);
    return 0;
}
