#include "/home/yangyi/Desktop/homework/weeks-six/code1/head.h"
int main(){
	int a[MAX];
	urand(a,MAX);
	printf("before---------\n");
	ushow(a,MAX);
	printf("\n");
	printf("later----------");
	mysort(a,MAX,sizeof(int),compar);
	maxshow(a);
	return 0;
}
