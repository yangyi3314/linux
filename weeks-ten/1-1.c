#include "my.h"
static void fun1(void)
{
    printf("invoked callbackfun!\n");

}
int main()
{
    FILE *fp;
    char buf[]="HELLO";
    atexit(fun1);
    printf("%s",buf);
    if((fp=open("text.txt","w+"))==NULL)
    {
        perror("fail to open!\n");
        return -1;
    }
    if(fputs(buf,fp)==EOF)
    {
        perror("fail to fputs");
        return -1;
    }
    return 0;
}