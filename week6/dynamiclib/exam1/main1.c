#include "/home/yangyi/Desktop/linuxprogram/weeks-six/dynamiclib/exam1/head.h"
#include<stdlib.h>
#include<dlfcn.h>
#include<stdio.h>
int main(){
	void * handle;
	int(*f1)();
	int(*f2)();
	int(*f3)();	
	int(*f4)();
	int(*f5)();
	char *error;
	handle=dlopen("/home/yangyi/Desktop/linuxprogram/weeks-six/dynamiclib/exam1/libdynamiclib.so",RTLD_LAZY);
	if(!handle)
	{
		perror("load failed!\n");
		exit(1);
	}
	f1=dlsym(handle,"urand");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f2=dlsym(handle,"ushow");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f3=dlsym(handle,"mysort");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f4=dlsym(handle,"maxshow");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f5=dlsym(handle,"compar");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	int a[MAX];
	f1(a,MAX);
	printf("before---------\n");
	f2(a,MAX);
	printf("\n");
	printf("later----------");
	f3(a,MAX,sizeof(int),f5);
	f4(a);
	if(dlclose(handle)<0)
	{

		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	return 0;
}
