#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
int main()
{
    int fd = open("../../test.txt",O_RDONLY);
    struct stat st;
    int ret = fstat(fd,&st);

    /*函数原型:
        void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
    */
    char* p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_PRIVATE,fd,0);
    /*返回值
        == MAP_FAILED   执行失败,并赋值error
        == 相应的地址    执行成功*/
    for(int i = 0;i<st.st_size;i++)
    {
        putchar(p[i]);
    }
    /*函数原型: int munmap(void *addr, size_t length);*/
    munmap(p,st.st_size);

    
    close(fd);
    return 0;

}