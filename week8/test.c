#include<stdio.h>
int main(int argc,char*argv[],char* env[])
{
    int i;
    extern char**environ;
    for (i=0 ; env[i]; i++)
    {
        printf("%d\n",env[i]);
    }

    for (i=0 ; environ[i]; i++)
    {
        printf("%d\n",environ[i]);
    }
    printf("%s\n",getenv("path"));
    return 0; 
}