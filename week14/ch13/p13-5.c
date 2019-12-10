#include "ch13.h"
#include <sys/mman.h>
#define STACK_GROWS_DOWN
#undef  STACK_GROWS_UP
void Hello(void)
{
   int array[512];
   printf("Hello, &array=%d\n", &array);
   Hello(); 
}
/* �����߳�ջ�ռ䲢����ջ�����������ջ��ַ������ҳ�߽��ϣ�ջ��С����Ϊҳ�ı��� */
void *thread_stack_alloc(size_t size)   
{
   int pagesize;
   void *mem, *guard_addr, *stack_addr;
   if (size < PTHREAD_STACK_MIN){
     fprintf(stderr, " thread_stack_alloc: SIZE less than PTHREAD_STACK_MIN\n");
     exit(1);
   }
   /* ����ջ��СΪҳ�������� */
   pagesize = sysconf(_SC_PAGESIZE);
   if(size % pagesize != 0)   
      size = ((size + pagesize) / pagesize) * pagesize;
   /* ���������ҳ�߽��ϵĴ洢�ռ䣬���а�����Ϊջ������Ķ���һҳ */
   mem = (void *)valloc(size + pagesize);
   /* ������������� */
#ifdef STACK_GROWS_UP
   guard_addr = mem + size;
   stack_addr = mem;
#else
   guard_addr = mem;
   stack_addr = mem + pagesize;
#endif
   if (mprotect(guard_addr, pagesize, PROT_NONE))
      err_exit("mprotect");
   printf("stack area=(%d,%d)\n", stack_addr, stack_addr+size-1);
   printf("gaurded area=(%d,%d)\n", guard_addr, guard_addr+pagesize-1);
   return stack_addr;
}
int main (void)
{
   pthread_t thread;
   int rv;
   pthread_attr_t attr;
   size_t stacksize, guardsize;
   char *stackaddr;
   pthread_attr_init(&attr);      /* ��ʼ���߳����Զ���*/
   /* ���������߳�ջ�Ŀռ� */
   stackaddr = (void *)thread_stack_alloc(PTHREAD_STACK_MIN); 
   /* �����߳����Զ����е�ջ��ַ�ʹ�С */
   rv = pthread_attr_setstack(&attr, stackaddr, PTHREAD_STACK_MIN); 
   check_error(rv, "pthread_setstack()");
   /* �鿴ջ����ֵ */   
   pthread_attr_getstack(&attr, (void *)&stackaddr, &stacksize);
   pthread_attr_getguardsize(&attr, &guardsize);
   printf("stack attributes: stackaddr=%d, stacksize=%d, guardsize=%d\n", 
           stackaddr, stacksize, guardsize);
   /* �����߳� */
   rv = pthread_create(&thread, &attr, (void *(*)())Hello, (void *)NULL);
   check_error(rv, "pthread_create()");
   pthread_attr_destroy(&attr);   /* ��ʱ�����߳����Զ��󣬱����ٴ�ʹ�� */
   check_error(rv, "pthread_attr_destroy()");
   /* ... ��̳������ ... */
   pthread_exit(NULL);
}
