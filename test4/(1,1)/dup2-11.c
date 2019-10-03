#include "head.h"


int main(){
	int fd,n,buf[100];
	dup2(1,1);
	while((n=read(0,buf,100))>0){
		write(1,buf,n);
	}
	return 0;
}
