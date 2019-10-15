#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void myfcopy(){
	FILE *fp= NULL;
	FILE *fd= NULL;
	char tmp[100];
	fp=fopen ("1.txt","rb");
	if(fp==NULL){
		printf("open original file error!\n");
		exit(1);
	}
	fd=fopen ("2.txt","wb+");
	if(fd==NULL){
		printf("open target file error!\n");
		exit(1);
	}
	while(fread(tmp,sizeof(tmp),1,fp)>0){
		if(fwrite(tmp,sizeof(tmp),1,fd)<0){
			perror("write file error\n");
		}
	}
	fclose(fp);
	fclose(fd);
}

void mycopy(){
	int fddes,fdsrc,nbytes,z;
	int buf[32];
	fddes=open("3.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
	fdsrc=open("1.txt",O_RDONLY,0644);
	if(fddes<0)
		exit(1);
	while((nbytes=read(fdsrc,buf,20))>0){
		z=write(fddes,buf,nbytes);
		if(z<0){
			perror("write file error!\n");
		}
	}
	close(fdsrc);
	close(fddes);
	printf("copy right!\n");
}

int main(){
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	myfcopy();
	gettimeofday(&t2,NULL);
	printf("Copy Right!\n");
	printf("f time is%f ms\n",1000*(t2.tv_sec-t1.tv_sec)+(t2.tv_usec-t1.tv_usec)/1000.0);
	gettimeofday(&t1,NULL);
	mycopy();
	gettimeofday(&t2,NULL);
	printf("Copy Right!\n");
	printf("time is%f ms\n",1000*(t2.tv_sec-t1.tv_sec)+(t2.tv_usec-t1.tv_usec)/1000.0);
	return 0;
}
