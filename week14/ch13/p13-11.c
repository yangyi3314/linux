#include "ch13.h"
typedef struct job_sync_data {
   int job_count;            //��ҵ��
   pthread_mutex_t mtx;     //���ڱ���job_count
   pthread_cond_t cond;     //����֪ͨjob_count�ĸı�
} job_sync_data; 
job_sync_data job_sync = {
              0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};
struct job {
   int job_id;
   void * work_ptr;
};
extern struct job *job_dequeue();          //����ҵ��������ȡһ����ҵ
extern void procee_job(struct job *ptr);  //����һ����ҵ
void worker_thread()
{
   struct job *curr_job;
   int rv;
   for(; ;){
      /* ����������������Ļ������ */
      rv=pthread_mutex_lock(&job_sync.mtx);  
      check_error(rv, "mutex lock");
      /* �����з���ҵ�����û����ȴ������������ȴ����ͷ������Ļ�������Ա������߳�
         �ܹ�������ҵ�ڶ���֮�С������������ȴ�����֮ǰ�����»�øû������ */
      while (job_sync.job_count == 0)
         pthread_cond_wait(&job_sync.cond, &job_sync.mtx);
      curr_job=job_dequeue(); // �õ���ҵ
      if (curr_job != NULL) 
         job_sync.job_count--; 
      // �ͷ������Ļ������
      rv=pthread_mutex_unlock(&job_sync.mtx);
      check_error(rv, "mtx_unlock failed");
      // ������ҵ
      procee_job(curr_job); 
   }
}
