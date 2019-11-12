#include "my.h"
static void callback1(){
   
      printf("---------callback1--------\n");
}
static void callback2(){
   
      printf("\n---------callback2--------\n");
}
static void __attribute__ ((constructor)) before_main()
{
      printf("---------constructor------\n");
}
static void __attribute__ ((destructor)) after_main()
{
      printf("\n---------desstructor------\n");
}
int main()
{
   atexit(callback1);
   atexit(callback2);
   FILE *fp;
   char buf[]={"test data from full buffer!\n"};
   if((fp=fopen("test.dat","w+"))==NULL)
     {
        perror("failed to fopen!\n");
        return -1;
     }
    if(fputs(buf,fp)==EOF)
     {
        perror("failed to fputs!\n");
        return -1;
     }
    printf("printf:data from line buffer\n");
   //exit(0);
   //_exit(0);
   //return 0;
}
