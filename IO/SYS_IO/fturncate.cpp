#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
    int fd = open("./sour.txt",O_RDWR);
    ftruncate(fd,1);
    close(fd);
    return 0;
}
