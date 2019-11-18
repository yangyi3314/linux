#include "head.h"

int main(){
	FILE *fp;
	char buf[100];
	int n,len;
	char *a="hello world";
	char *b="my";
	fp=fopen("a.txt","wr+");
	if(fp<0)
		perror("openfile error \n");
	fwrite(a,11,1,fp);
	fseek(fp,0,SEEK_END);
	len=ftell(fp)-6;
	fseek(fp,6,SEEK_SET);
	while((n=fread(buf,1,100,fp))>0){
		printf("%s\n",buf);
	}
	fseek(fp,6,SEEK_SET);
	if((n=fwrite(b,2,1,fp))<0)
		perror ("write file error \n");
	fwrite(buf,1,len,fp);
	fclose(fp);
	return 0;
}
