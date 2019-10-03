#include "head.h"


int main(){
	int fd,n,buf[100];
	dup2(1,2);
	perror("open file error!\n");
	return 0;
}
