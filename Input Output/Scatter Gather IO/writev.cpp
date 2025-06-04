#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <string.h>
#include <unistd.h>

int main()
{   
    int fd = open("./text.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd < 0)
    {
        perror("open():");
        exit(1);
    }

    /*函数原型:
        #include <sys/uio.h>
        ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
        struct iovec {
//          void  *iov_base;    /* Starting address */
//          size_t iov_len;     /* Number of bytes to transfer */
//      };
    struct iovec iov[3];
    char str1[] = "The open file description records the file offset\n";
    iov[0].iov_base = str1;
    iov[0].iov_len = strlen(str1) + 1;
    char str2[] = "The argument flags must include one of the following access modes\n";
    iov[1].iov_base = str2;
    iov[1].iov_len = strlen(str2) + 1;
    char str3[] = "The  full  list of file creation flags and file status flags is as follows\n";
    iov[2].iov_base = str3;
    iov[2].iov_len = strlen(str3) + 1;

    ssize_t ret = writev(fd,iov,3);
    /*返回值:
        == -1   失败   
        >0      读取到的字节数*/
    if(ret < 0)
    {
        perror("writev():");
        exit(1);
    }
    printf("write %zd bytes\n",ret);

    close(fd);
    return 0;
}