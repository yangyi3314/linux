#include"alterpower.h"
void alterpower()
{
    int mode;
    int mode_u;//所有者权限
    int mode_g;//所属组权限
    int mode_o;//其他人权限
    char filename[100],*path;
    printf("Input the file name:");
    scanf("%s",filename);
    path=filename;
    printf("alter file power is(000-777):");
    scanf("%d",&mode);
    if(mode>777||mode<0){//验证要设置的权限是否合法
        printf("Error mode!\n"); 
    }else
    {
        mode_u=mode/100; 
        mode_g=mode/10%10;
        mode_o=mode%10;
        mode=mode_u*8*8+mode_g*8+mode_o;//八进制转换
        if(chmod(path,mode)==-1)//调用chmod函数进行权限修改
        {
        perror("Error alter!\n");
        }else
        {
            printf("alter power succeed!\n");
        }
    }
}