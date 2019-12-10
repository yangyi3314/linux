#include "ch13.h"
#define SIZE 100
int a[SIZE],b[SIZE];
int max;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void max_fun(int *arg)    /* ����max(max, arg[]) */
{
   int * ap=arg;
   int rv, i, l_max;
   for (i=1; i<SIZE; i++){ // �ҳ�����ap�е����ֵ
      if (ap[i] > l_max) 
         l_max = ap[i];
   }
   /* ����max(L_max, max),�軥����� */
   rv = pthread_mutex_lock(&mtx);      // ��û������
   check_error(rv, "mutex_lock ");
   if (l_max > max)
      max = l_max;
   rv = pthread_mutex_unlock(&mtx);   // �ͷŻ������
   check_error(rv, "mutex_unlock ");
   pthread_exit(NULL);       
}

int main(void)
{
   pthread_t tid1,tid2;    // �̱߳�ʶ
   int i, rv;
   
   for (i=1; i<SIZE; i++){ // ��������Ԫ�ص�����
      a[i]=rand();
      b[i]=rand();
   }
   /* ����2���߳�ִ�к���max_fun()�ֱ�������a��b */
   rv = pthread_create(&tid1, NULL, (void*(*)())max_fun, a);
   check_error(rv, "pthread_create: tid1");
   rv = pthread_create(&tid2, NULL, (void*(*)())max_fun, b);
   check_error(rv, "pthread_create: tid2");
   /* �ȴ�2���߳̽��� */
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf ("max value = %d\n", max);
   exit(0);
}
