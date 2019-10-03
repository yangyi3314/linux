#include "head.h"


int main(){
	int fd,n,buf[100];
	dup2(1,0);
	while((n=read(0,buf,100))>0){
		write(0,buf,n);
	}
	return 0;
}
