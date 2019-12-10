#include "my.h"

void * fun(void *arg)
{
     
      struct sendval * k= (struct sendval *)arg;
      int i=0,sum=0;
      for(i=0;i<k->s;i++)
            sum+=i;
      printf("worker---%d : pthread_self return %p,sum of %d = %d\n",k->n,(void*)pthread_self(),k->s,sum);
     
      pthread_exit(NULL);
      return NULL;
     
}

int main()
{
   pthread_t tid[NUM];
   int ret[NUM],i;
   struct sendval d;
   for(i=0;i<NUM;i++){
    d.n=i;
    d.s=100*(i+1);
    ret[i] = pthread_create(&tid[i],NULL,fun,(void *)&d);
   if (ret[i] !=0)
     {
        perror("create failed!\n");
        return -1;
     }
      


   } 
   for(i=0;i<NUM;i++)
      pthread_join(tid[i],NULL); 
  
   printf("Master %d : All Done!\n",getpid());
   return 0;
}
