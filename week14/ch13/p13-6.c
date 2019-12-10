#include "ch13.h"
#include <sys/shm.h>
#include "xmalloc.c"
/* ����һ����̬����ռ䡢���ж������ԵĻ������ */
pthread_mutex_t *mutex_customized (int shared, int type, int key)
{
   int rv;
   key_t shmid;
   pthread_mutex_t *mtx;
   pthread_mutexattr_t mtxattr;  // ����������Զ���
   /* ��ʼ������������Զ��� */
   rv = pthread_mutexattr_init (&mtxattr);
   check_error(rv, "mutexattr_init ");
   /* ���ù������� */
   rv = pthread_mutexattr_setpshared(&mtxattr, shared);
   check_error(rv, " mutexattr_setpshared ");
   /* �����������ԣ����е�ϵͳ����Ҫ��ȷ�����������Ժ�_GNU_SOUCE */
   rv = pthread_mutexattr_settype (&mtxattr, type);
   check_error(rv, "mutexattr_settype");
   /* Ϊ����������乲��洢�ռ� */
   if (shared == PTHREAD_PROCESS_PRIVATE)
      mtx = (pthread_mutex_t *)xmalloc(sizeof(pthread_mutex_t));     
   else {  // ���̹�������������ڹ���洢��
      shmid = shmget(key, sizeof(pthread_mutex_t), 0666|IPC_CREAT);
      if (shmid == -1) 
          err_exit("shmget error");
      mtx = (pthread_mutex_t *)shmat(shmid, (char *)0, 0);
      if ((int)mtx == -1) 
         err_exit("shmget error");
   }
   /* �����Զ����ʼ��mtx */
   rv = pthread_mutex_init(mtx, &mtxattr);
   check_error(rv, "mutex_init ");
   /* �������ٲ�����Ҫ�����Զ��� */
   rv=pthread_mutexattr_destroy(&mtxattr);
   check_error(rv, "mutexattr destroy ");
   return (mtx);
} 
#define KEY 8125
pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER;  // ��̬��ʼ���Ľ���˽�л������
pthread_mutex_t mtx2;       // ��̬��ʼ���Ľ���˽�л������
pthread_mutex_t *mtx3;      // ���̹��������
int main(void)
{
   int rv;
   // ...
   rv = pthread_mutex_init (&mtx2, NULL); // ��ʼ��mtx2Ϊϵͳȱʡ�������
   /*��ʼ��mtx3Ϊ���ƵĽ��̹���ݹ黥�����*/
   mtx3 = mutex_customized(PTHREAD_PROCESS_SHARED,
                            PTHREAD_MUTEX_RECURSIVE,KEY);
   // ...Ӧ�ó������������
   /* ����mtx2 */
   rv = pthread_mutex_destroy(&mtx2);
   check_error(rv, "mutex_destroy: mtx2");
   pthread_exit(NULL);
}
