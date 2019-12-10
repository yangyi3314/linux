#include "ch13.h"
#define NUM_THREADS 4 
#define VECL 4*10000000
double a[VECL], b[VECL], sum;
struct args {         // dotsumʹ�õ�����
   pthread_t tid;       // �߳�ID
   int l_sum;           // �ֲ����
   int index;               // ��0��ʼ���̱߳��
} tharg[NUM_THREADS];     // ÿ���̶߳�Ӧһ��Ԫ��
void *dotsum(void *arg)   // �󲿷ֵ�����߳̿�ʼ����
{
   struct args *ap = (struct args *)arg;
   int  i, start, end;
   double l_sum = 0.0;                           // �ֲ����
   start = ap->index * (VECL/NUM_THREADS);   // ������ʼ�� 
   end   = start + (VECL/NUM_THREADS);        // ���������� 
   printf("thread %i do from index %d to %d\n",ap->index, start,end-1);
   for (i = start; i < end; i++) 
      l_sum += (a[i]*b[i]);
   ap->l_sum = l_sum;                           // ��������� 
   return;
}
int main(void)
{
   int  i;
   assert(VECL%4==0);                  // ֻ������������������ȷ 
   for (i=0; i<VECL; i++)
      a[i]=b[i]=1.0;
   for(i=1; i<NUM_THREADS; i++) {  // ����NUM_THREADS-1���̲߳���ִ��dotsum()���� 
      tharg[i].index = i;
      pthread_create(&tharg[i].tid, NULL, dotsum, (void *)&tharg[i]);
   }
   tharg[0].index = 0;
   dotsum((void *)&tharg[0]);      /* ���̲߳������ */
   for(i=1; i<NUM_THREADS; i++)   /* �ȴ������߳���ɼ��� */
      pthread_join(tharg[i].tid, (void **)NULL);
   /* �ۼ�ÿ���̵߳Ĳ��ֺͲ������� */
   sum=0.0;
   for (i=0; i<NUM_THREADS; i++)
      sum += tharg[i].l_sum;
   printf ("Sum =  %lf \n", sum);
   pthread_exit(NULL);
}
