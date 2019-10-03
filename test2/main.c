#include "head.h"
int main(){
	int a[MAX];
	urand(a,MAX);
	printf("before---------\n");
	ushow(a,MAX);
	printf("later----------\n");
	mysort(a,MAX,sizeof(int),compar);
	ushow(a,MAX);
	return 0;
}
