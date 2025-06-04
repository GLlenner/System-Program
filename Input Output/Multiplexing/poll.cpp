#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*函数原型
    int poll(struct pollfd *fds, nfds_t nfds, int timeout);*/
    /*struct pollfd 结构体:
    {
//      int   fd;         /* file descriptor */
//      short events;     /* requested events */
//      short revents;    /* returned events */
//  }

    struct pollfd pollfds[2];

    pollfds[0].fd = STDIN_FILENO;
    pollfds[0].events = POLLIN;

    pollfds[1].fd = STDOUT_FILENO;
    pollfds[1].events = POLLOUT;

    /*timeout 单位为毫秒*/
    int ret = poll(pollfds,2,5000);
    if(ret < 0)
    {
        perror("poll():");
        exit(1);
    }
    else if(ret == 0)
    {
        printf("timeout/n");
        exit(1);
    }


    /*判断是否该文件符符合要求*/
    if(pollfds[0].revents & POLLIN)
    {
        printf("stdin can read\n");
    }
    if(pollfds[1].revents & POLLOUT)
    {
        printf("stdout can write\n");
    }
    return 0;
}