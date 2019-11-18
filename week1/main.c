#include "head.h"
int main(){
	int a[MAX],b[MAX],i;
	struct timeval t1,t2,t3;
	urand(a,b,MAX);
	gettimeofday(&t1,NULL);
	usort(a,MAX);	
	gettimeofday(&t2,NULL);
	qsort(b,MAX,sizeof(int),compar);
	gettimeofday(&t3,NULL);
	printf("the time of usort 1w data:\n%f ms\n",1000*(t2.tv_sec-t1.tv_sec)+(t2.tv_usec-t1.tv_usec)/1000.0);
	printf("the time of qsort 1w data:\n%f ms\n",1000*(t3.tv_sec-t2.tv_sec)+(t3.tv_usec-t2.tv_usec)/1000.0);
	return 0;
}
