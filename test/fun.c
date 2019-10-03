#include"head.h"
void usort(int *a,int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}

int compar(const void *a,const void *b)
{
int *aa=(int *)a,*bb=(int *)b;
if(*aa>*bb)return 1;
else if(*aa=*bb)return 0;
else return -1;
}

void urand(int *a,int *b,int n)
{
int i;
srand((unsigned)time(NULL));
for(i=0;i<n;i++)
{
a[i]=b[i]=(int)(rand()%10000+1);
}
}
