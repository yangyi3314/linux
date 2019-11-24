#include<stdio.h>
#include<time.h>
void ini_damon(void);
int main()
{
    FILE *p;
    time_t t;
    init_daemon();
    while (1)
    {
        sleep(10);
        if((fp=fopen("6-8.log",a))>=0)
        {
            t=time(0);
            fprintf(fp,"  :%s",asctime(localtime(&t)));
            fclose(fp);
        }
    }
    
}