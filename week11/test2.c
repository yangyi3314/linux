#include"my.h"
int main()
{
    int pid;
    if((pid=fork())<0)
    {
        perror("failed to fork@\n");
        return -1;
    }
    else if(pid==0)
    {
        printf("%d:child is running now!\n",getpid());
        while(1);
        printf("%d:child is exit now!\n",getpid());
        exit(0);

    }
    else
    {
        printf("%d:parent is waiting zombie now\n",getpid());
        sleep(10);
        printf("%d:parent is exiting now!\n",getpid());
    }
    exit(0);
}