#include "head.h"

int main(){
	int fd,n;
	int buf[100];
	fd=open("1.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	if(fd<0)
		perror("open file error");
	dup2(fd,0);
	while((n=read(0,buf,100))>0){
		write(1,buf,n);
	}
	return 0;
}
