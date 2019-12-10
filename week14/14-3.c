#include "my.h"

void fun(void *arg)
{
    printf("worker thread is runnig.pid=%d\n",getpid());
     
}

int main()
{
   pthread_t tid;
   int ret;
   ret = pthread_create(&tid,NULL,(void *(*)())fun,NULL);
   if (ret !=0)
     {
        perror("create failed!\n");
        return -1;
     }
   pthread_join(tid,NULL);
   printf("Master %d : All Done!\n",getpid());
   return 0;
}
