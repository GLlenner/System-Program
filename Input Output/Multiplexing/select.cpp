/*学习使用 select 函数*/


#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{   

    /*
    int select(int nfds, fd_set *readfds, fd_set *writefds,
                  fd_set *exceptfds, struct timeval *timeout);
    nfds:所有描述符最大值加1              
    */

    /*设置超时时间*/
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    int ret;
    fd_set readfds;
    FD_ZERO(&readfds);/*清空文件描述符集*/
    FD_SET(STDIN_FILENO,&readfds); /*将stdin 添加到文件描述符中*/
    ret = select(STDIN_FILENO + 1,&readfds,NULL,NULL,&timeout);
    /*注意: 当调用 select 后,参数fd_set *readfds, fd_set *writefds,
    fd_set *exceptfds, struct timeval *timeout,都会被改变*/
    if(ret < 0)/*返回值为 -1 时,出错*/
    {
        perror("select():");
        exit(1);
    }
    else if(ret == 0)/*返回值为 0 时,超时返回*/
    {
        fprintf(stderr,"timeout\n");
        exit(0);
    }

    /*如果返回值 >0*/
    if(FD_ISSET(STDIN_FILENO,&readfds))
    {
        int len = 0;
        char buf[1025];
        len = read(STDIN_FILENO,buf,1024);
        buf[len] = '\0';
        printf("read:%s\n",buf);
    }
    return 0;
}
