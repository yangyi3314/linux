#include "/home/yangyi/Desktop/homework/dynamiclib/exam2/head.h"
int main(){
	void * handle;
	int(*f1)();
	int(*f2)();
	int(*f3)();	
	int(*f4)();
	char *error;
	handle=dlopen("/home/yangyi/Desktop/homework/dynamiclib/exam1/libynamiclib.so",RTLD_LAZY);
	if(!handle)
	{
		perror("load failed!\n");
		exit(1);
	}
	f1=dlsym(handle,"urand");
	if(error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f2=dlsym(handle,"ushow");
	if(error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f3=dlsym(handle,"mysort");
	if(error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f4=dlsym(handle,"maxshow");
	if(error=dlerror())!=NULL)
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
	f3(a,MAX,sizeof(int),compar);
	f4(a);
	if(dlclose(handle)<0)
	{

		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	return 0;
}
