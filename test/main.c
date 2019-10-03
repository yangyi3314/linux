#include"head.h"
int main(){
int a[MAX],b[MAX],i;
clock_t first,second,third;
urand(a,b,MAX);
first=clock();
usort(a,MAX);
second=clock();
qsort(b,MAX,sizeof(int),compar);
third=clock();
printf("the time used for usort is:%ld ms \n",second-first);
printf("the time used for qsort is:%ld ms \n",third-second);
return 0;
}
