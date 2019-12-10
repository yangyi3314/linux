#include "ch13.h"
extern struct job *create_job();            //����һ����ҵ
extern void job_enqueue(struct job *ptr); //����ҵ�������һ����ҵ
typedef struct job_sync_data {
   int job_count;            //��ҵ��
   pthread_mutex_t mtx;     //���ڱ���job_count
   pthread_cond_t cond;     //����֪ͨjob_count�ĸı�
} job_sync_data;
extern job_sync_data job_sync;
void master_thread()
{
   struct job *new_job;
   int rv;
   for (; ;) {
      if ((new_job = create_job())== NULL)  // ������һ����ҵ
         pthread_exit((void *)NULL);         // û�н�һ���Ĺ�������ֹ�Լ�
      /* ��������Ļ������ */
      rv=pthread_mutex_lock(&job_sync.mtx); 
      check_error(rv, "mutex lock");
      /* �������ҵ����ҵ���� */
      job_enqueue(new_job);
      job_sync.job_count++;
      /* �������������źŻ���һ���߳� */
      rv = pthread_cond_signal(&job_sync.cond);
      check_error(rv,"cond_signal");  
      /* �ͷ������Ļ������ */
      rv=pthread_mutex_unlock(&job_sync.mtx);
      check_error(rv,"mtx_unlock");
   }
}
