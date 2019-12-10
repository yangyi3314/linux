#include "my.h"

void * threadfun(void *arg)
{
   pthread_exit(NULL);
}

int main()
{
   pthread_t tid;
   int i,ret;
   struct timeval tv1,tv2;
   struct timezone tz;
   gettimeofday(&tv1,&tz);
   for(i=0;i<10000;i++)   
     {
        ret=pthread_create(&tid,NULL,threadfun,NULL);
        if(ret != 0)
             {
               perror("create thread failed!\n");
               return -1;
             }
 
     }
   gettimeofday(&tv2,&tz);
   printf("runing time is %ld\n",tv2.tv_usec-tv1.tv_usec);
   return 0;
}
