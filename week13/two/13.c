#include"my.h"
volatile int global=0;
void alarmhandler(int signo)
{
    global=1;
    puts("catch alarm!\n");
}
int main()
{
    clock_t start,stop;
    struct tms buffer;
    signal(SIGALRM,alarmhandler);
    start=times(&buffer);
    alarm(1);
    while(!global);
    printf("%ld clock ticks per second (start=%ld,stopp=%ld)\n",stop-start,start,stop);
    printf("sysconf(_SC_CLK_TCK = %ld\n",sysconf(_SC_CLK_TCK));
    return 0;
}