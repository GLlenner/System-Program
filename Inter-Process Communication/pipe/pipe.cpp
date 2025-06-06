#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{   

    char buf[1024];
    int pd[2];
    /*函数原型：int pipe(int pipefd[2]);*/
    int ret = pipe(pd);
    /*返回值：
        ==0     成功返回
        ==-1    失败返回*/
    if(ret < 0)
    {
        perror("pipe()");
        exit(1);
    }
    int pid = fork();
    if(pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if(pid > 0)//父进程读
    {
        close(pd[1]);
        int len = read(pd[0],buf,1024);
        write(1,buf,len);
        printf("father pid :%d\n",getpid());
        close(pd[0]);
        wait(NULL);
    }
    else if(pid == 0)//子进程写
    {
        close(pd[0]);
        write(pd[1],"HELLO!",6);
        close(pd[1]);
        return 0;
    }
    return 0;
}