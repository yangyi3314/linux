#include "head.h"

int main(){
	int fd;
	fd=open("1.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	if(fd<0){
		perror("open file error\n");
	}
	dup2(fd,2);
	open("2.txt",O_RDWR);
	perror("open file error");
	close(fd);
	return 0;
}
