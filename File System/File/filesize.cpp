//使用stat()，查看文件大小

/*
int stat(const char *pathname, struct stat *statbuf);会跟随符号链接，返回目标文件的信息
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);不会跟随符号链接，返回的是符号链接本身的信息
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    struct stat statbuf;
    stat("./sour.txt",&statbuf);
    printf("inode:%d size:%d\n",statbuf.st_ino,statbuf.st_size);
    
    int fd = open("./sour2.txt",O_RDONLY);
    fstat(fd,&statbuf);
    printf("inode:%d size:%d\n",statbuf.st_ino,statbuf.st_size);
    return 0;
}
