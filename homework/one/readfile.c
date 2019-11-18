#include"readfile.h"
void readfile()
{
    FILE* fp;
    char ch,filename[100];
    printf("Input the file name:");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("open file fail!\n");
    }
    while (ch!='\n'&&ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    printf("\n");
}