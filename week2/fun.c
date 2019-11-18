#include "head.h"

int compar(const void *a,const void*b){
	int *aa=(int *)a,*bb=(int *)b;
	if(*aa>*bb)return 1;
	else return 0;
}
void urand(int *a,int n){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		a[i]=(int)(rand()%1000+1);
	}
}
void ushow(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
void mysort(void *base,size_t len,size_t width,int (*Comp)(const void *,const void *))
{
	int i=0,j=0;
	char *p=(char*)base;
	for(i=0;i<len;i++){
		for(j=0;j<len-i-1;j++){
			if(1==Comp((void*)(p+j*width),(void*)(p+(j+1)*width))){
				char *temp=(char*)malloc(width);
				memcpy(temp,p+j*width,width);
				memcpy(p+j*width,p+(j+1)*width,width);
				memcpy(p+(j+1)*width,temp,width);
				free(temp);
			}
		}
	}
}
void syssort(void *base,size_t len,size_t width){
	qsort(base,MAX,sizeof(int),compar);
}
