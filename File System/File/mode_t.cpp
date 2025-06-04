/*
mode_t 变量可以使用宏来判断
属性:S_ISREG(m)	普通文件
S_ISDIR(m)	目录
S_ISLNK(m)	符号链接
S_ISCHR(m)	字符设备文件
S_ISBLK(m)	块设备文件
S_ISFIFO(m)	FIFO/管道
S_ISSOCK(m)	套接字
*/
/*本质上是位图*/

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
    if (S_ISDIR(statbuf.st_mode))
    {
        printf("It's a directory.\n");
    } 
    else
    {
        printf("It's not a directory.\n");
    }
    return 0;
}