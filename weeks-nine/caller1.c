#include "my.h"
int main()
{
    int ret;
    printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=system("/home/yangyi/Desktop/linux/weeks-nine");
    sleep(100);
    return 0;
}
