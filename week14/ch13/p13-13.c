#include "ch13.h"
typedef struct barrier_struct {  //barrier���ݽṹ
   int             valid;           //�Ϸ���ʼ����־
   pthread_cond_t   cv;             //��������
   pthread_mutex_t  mtx;            //�����Ļ������
   int   predicate;                 //����ν��,��ͬ��դ��ͬ���������ͬ��ֵ
   int   barrier_val;               //Ҫ�ȴ����̸߳���
   int   blocked_threads;           //�ѵ�����̸߳���
} barrier_t;                             
/* ���ڱ���barrier��ʼ���Ļ������ */
pthread_mutex_t barrier_init_mutex = PTHREAD_MUTEX_INITIALIZER;
#define BARRIER_VALID 546731      //barrier��ʼ����־
/* barrier b��ʼ������ */
int barrier_init(barrier_t *b, int val)
{
   int rv;
   /* ����barrier_init_mutex,ʹ��ÿ��ֻ����һ���߳̽��г�ʼ�� */
   if ((rv=pthread_mutex_lock(&barrier_init_mutex))!=0) 
      return (rv);   //��������
   if (b->valid == BARRIER_VALID) { // �ѽ��й���ʼ�����˴�Ϊ���³�ʼ��
      /* �������դ�������������Ļ������ */
      if ((rv=pthread_mutex_lock(&b->mtx))!=0){ 
         pthread_mutex_unlock(&barrier_init_mutex); 
         return(rv);
      }
      if (b->blocked_threads !=0 ){// ��barrier������ȴ����̣߳����ش���
         pthread_mutex_unlock(&b->mtx);
         pthread_mutex_unlock(&barrier_init_mutex);
         return(EBUSY);
      }
      /* ����barrier����ֵ�󷵻� */
      b->barrier_val=val;
      if ((rv=pthread_mutex_unlock(&b->mtx))!=0) {
         pthread_mutex_unlock(&barrier_init_mutex);
         return(rv);
      }
   }else {  // �״γ�ʼ��
      if ((rv=pthread_mutex_init(&b->mtx, NULL))!=0)
         return (rv); 
      if ((rv=pthread_cond_init(&b->cv, NULL)) !=0) {
         pthread_mutex_unlock(&barrier_init_mutex);
         return (rv);
      }
      b->barrier_val=val;
      b->blocked_threads =0;
      b->predicate =0;
      b->valid = BARRIER_VALID;
   }
   if ((rv=pthread_mutex_unlock(&barrier_init_mutex))!=0) // �ͷ�����Ȼ�󷵻�
      return (rv);
   return (0);
}  
  
/* դ���ȴ����� */
int barrier_wait(barrier_t *b)
{
   int rv, predicate;
   if (b->valid != BARRIER_VALID) // ���դ���ĺϷ���
      return(EINVAL);             // դ��δ��ʼ������
   if ((rv=pthread_mutex_lock(&b->mtx)) != 0) //��������դ�������������Ļ������
      return (rv);     // ��������
   predicate = b->predicate;  // ���汾��ͬ��ν��ֵ
   b->blocked_threads++;       // ���ӵ����̼߳���
   if (b->blocked_threads == b->barrier_val) {  // ������󵽴���߳�
      /* Ϊ�´�ͬ������դ��ֵ */
      b->predicate += 1;                     
      b->blocked_threads = 0; 
      /* ��������������߳� */
      if ((rv=pthread_cond_broadcast(&b->cv))!= 0) { 
          pthread_mutex_unlock(&b->mtx); // �㲥����,�ͷŻ�������󷵻�
          return(rv);  
      }
   }else{              // �����ȵ�����߳�
      /* �ȴ���ֱ�������̶߳��ѵ��� */
      while (b->predicate == predicate){
         rv = pthread_cond_wait(&b->cv, &b->mtx);
         if ((rv!=0)&&(rv!=EINTR)){
            pthread_mutex_unlock(&b->mtx);
            return(rv);  // �����ȴ�����,�ͷŻ�������󷵻�
         }
      }
   }
   /* դ��ͬ���������ͷ�����դ�������������Ļ������ */
   if ((rv=pthread_mutex_unlock(&b->mtx))!=0)
      return(rv);   // �ͷ�������
   return(0);  // ��������
}
