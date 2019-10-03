#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	FILE *f1= NULL;
	FILE *f2= NULL;
	char temp[100];
	f1=fopen ("1.txt","rb");
	if(f1==NULL){
		printf("open original file error!\n");
		exit(1);
	}
	f2=fopen ("2.txt","wb+");
	if(f2==NULL){
		printf("open target file error!\n");
		exit(1);
	}
	while(fread(temp,32,1,f1)>0){
		if(fwrite(tmp,32,1,f2)<0){
			perror("write file error\n");
		}
	}
	fclose(f1);
	fclose(f2);
	printf("Copy Right!\n");
	return 0;
}
