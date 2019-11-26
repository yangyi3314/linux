#include "my.h"
int main()
{
    int pid,fd[2],len;
    char buf[1024*64];
    FILE *stream;
    if(pipe(fd)!=0)
    {
        fprintf(stderr,"pipe create failed.\nerror reason=%s\n",strerror(errno));
        return -1;
    }
    pid=fork();
    if(pid =<0)
    {
        fprintf(stderr,"fork failed.\nerror reason=%s\n",strerror(errno));
        return -2;
    }
    else if(pid==0)
    {
        close(fd[1]);
        up2(fd[0],0);
        close(fd[0]);
        if(excel("/bin/car","car",NULL,NULL)==-1)
        {
            fprintf(stderr,"excel failed.\nerror reason=%s\n",strerror(errno));
            return -3;
        }
    }
}