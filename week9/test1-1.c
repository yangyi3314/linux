#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int x=100;
int main(int argc,int **argv)
{
    int y=0;
    int i;
    static int w=33;
    printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
    for(i=0;i<argc;i++)
    {
        printf("%d:%s\n",i,argv[i]);
    }
    printf("test1:address x=%ld,y=%ld,w=%ld\n",&x,&y,&w);
    sleep(100);
    return 0;
}
