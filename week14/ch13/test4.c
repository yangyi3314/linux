#include "my.h"
struct sarg{
   int n;
   int m;
};
struct rarg{
   int s;
   long t;
};
void *fun(void *n)
{
  struct sarg *pt=(struct sarg *)n;
  struct rarg *pk=(struct rarg *)malloc(sizeof(struct rarg));
  struct timeval tv1,tv2;
  struct timezone tz;
  
  int i,s=0;
  gettimeofday(&tv1,&tz);
  for(i=0;i<pt->m;i++)
        s+=i;
  gettimeofday(&tv2,&tz);
  printf("worker thread %d  sum=%d \n",pt->n,s);
  pk->s=s;
  pk->t=tv2.tv_usec-tv1.tv_usec;
  printf("%d:pk.s=%d,pk.t=%ld\n",pt->n,pk->s,pk->t);
  pthread_exit((void *)pk);
  return (void *)0;

}

int main()
{
   pthread_t tid[4];
   int ret[4],i;
   struct rarg v[4];
   struct sarg s[4];
   for(i=0;i<4;i++)
    {
       s[i].n=i+1;
       s[i].m=10000*(i+1);
       ret[i]=pthread_create(&tid[i],NULL,fun,(void*)&s[i]);
       if(ret[i] != 0)
         {
             perror("failed!\n");
             return -1;
         }
       pthread_join(tid[i],(void *)&v[i]);
    }
   for(i=0;i<4;i++)
      printf("sum=%d,time=%ld\n",v[i].s,v[i].t);
   return 0;
}
