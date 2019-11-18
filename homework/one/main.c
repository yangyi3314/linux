#include "main.h"

int main()
{
    while(1)
    {
    int choose;
    printf("**************************************\n");
    printf("0.退出\n");
    printf("1.创建新文件\n");
    printf("2.写文件\n");
    printf("3.读文件\n");
    printf("4.修改文件权限\n");
    printf("5.查看当前文件的权限\n");
    printf("**************************************\n");
    printf("请输入你的选择：");
    scanf("%d",&choose);
    switch(choose)
    {
        case 0:exit(0);
        case 1:
            newfile();
            break;
        case 2:
            writefile();
            break;
        case 3:
            readfile();
            break;
        case 4:
            alterpower();
            break;
        case 5:
            readpower();
            break;
    }
    }
}