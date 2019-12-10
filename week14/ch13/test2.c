#include "my.h"

void *fun(void *arg)
{
   int y=(int )arg;
   sleep(y*5);
   printf("%d worker thread is running.\n",y);
   pthread_exit((void*)&y);
}
int main()
{
  pthread_t tid[4];
  int i,ret[4];
  for(i=0;i<4;i++)
    {
      ret[i]=pthread_create(&tid[i],NULL,fun,(void*)i);
      if(ret[i]!=0)
        {
          perror("failed!\n");
          return -1;
        }
       pthread_join(tid[i],NULL);
       //pthread_detach(tid[i]);
    }
  
   
  printf("Master thread done!\n");
  //sleep(30);
  return 0;

}
