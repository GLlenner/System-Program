//重定向功能学习
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    
    int fd = open("./dup.txt",O_RDWR|O_CREAT|O_TRUNC,0600);
    if(dup2(fd,1) < 0)
    {
        perror("open()");
        exit(1);
    }
    //////////////////////
    fprintf(stdout,"Hello,world\n");
    fflush(stdout);
    close(fd);
    close(1);
    return 0;
}
