#include"newfile.h"

void newfile()
{
    FILE* fp;
    char ch,filename[100];
    printf("Input the file name:");
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf( "create File [ %s ] fail!\n", filename);
    }else
    {
        printf( "create File [ %s ] succeed!\n", filename);
    }
}