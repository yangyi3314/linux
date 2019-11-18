#include"writefile.h"

void writefile()
{
    FILE* fp;
    char ch,filename[100],comment[1000];
    printf("Input the file name:");
    scanf("%s",filename);
    if((fp=fopen(filename,"wb"))==NULL)
    {
        printf("open file fail!\n");
    }
    printf("please write:");
    scanf("%s",comment);
    fputs(comment,fp);
    fclose(fp);
    printf("write succeed!\n");
}