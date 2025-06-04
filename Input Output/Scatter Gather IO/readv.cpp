#include <fcntl.h>
#include <sys/uio.h>
#include <stdio.h>

int main()
{   
    int fd = open("./text.txt",O_RDONLY);
    char str1[51],str2[67],str3[76];

    struct iovec iov[3];
    iov[0].iov_base = str1;
    iov[0].iov_len = sizeof(str1);
    iov[1].iov_base = str2;
    iov[1].iov_len = sizeof(str2);
    iov[2].iov_base = str3;
    iov[2].iov_len = sizeof(str3);

    /*ssize_t readv(int fd, const struct iovec *iov, int iovcnt);*/
    ssize_t ret = readv(fd,iov,3);

    printf("str1: %s",str1);
    printf("str2: %s",str2);
    printf("str3: %s",str3);

    return 0;
}