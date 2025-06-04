//使用系统调用删除文件中的某一行

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv)
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage: <file>");
        exit(1);
    }
    printf("%s",argv[1]);
    int rfd = open(argv[1],O_RDONLY);
    int wfd = open(argv[1],O_RDWR);
    if(rfd < 0 || wfd < 0)
    {
        perror("open()");
        exit(1);
    }

    char buf[1024];
    int line = 1;
    int pos = 0;
    int recnum = 0;
    int start = 0;
    int end = 0;
    while((recnum = read(rfd,buf,1024)) > 0)
    {
        if(line == 10)
        {
           for(start = 0;start < recnum;start++)
           {
                if(buf[start] == '\n')
                {
                    line++;
                    pos += write(wfd,buf+start,recnum-start);
                    break;
                }
           }
        }
        else
        {
            for(end = 0;end < recnum;end++)
            {
                if(buf[end] == '\n')
                {
                    line++;
                    if(line == 10)
                    {
                        break;
                    }
                }
            }
            pos += write(wfd,buf,end);
            if(line == 10)
            {
                for(start = end + 1;start < recnum;start++)
                {
                    if(buf[start] == '\n')
                    {
                        line++;
                        pos += write(wfd,buf+start,recnum-start);
                        break;
                    }
                }
            }
        }
    }
    close(rfd);
    close(wfd);
    int fd = open(argv[1],O_RDWR);
    ftruncate(fd,pos);    
    close(fd);
    exit(0);
}