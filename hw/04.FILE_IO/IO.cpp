#include<unistd.h>  //read,write,open,close 要引入
#include<fcntl.h>  //O_RDWR | O_CREAT | O_TRUNC要引入
#include<stdio.h>

int main(){
    char* filename = "./test.txt";
    int open_flag = O_RDWR;
    // int open_flag = O_RDWR | O_CREAT | O_TRUNC;
    int fd = open(filename,open_flag);
    if(fd == -1){
        char err_msg[30];
        snprintf(err_msg,sizeof(err_msg),"can't not open %s",filename);
        perror(err_msg);//打印一条错误信息，包括你提供的前缀字符串 errmsg 和 errno 对应的错误描述。
    }
    char msg[101];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, msg, 100*sizeof(char))) > 0) {
        // read的返回值是读取到的字符个数
        //printf("%d\n",bytes_read);
        msg[bytes_read] = '\0';// 添加 '\0' 让它变成一个合法的字符串，确保不会越界打印
        printf("%s", msg);
    }
    //bytes_read = write(fd,msg,sizeof(msg));//write 和 read 遇到'\0'字符都不会停止读入和写入
    //printf("%d\n",bytes_read);
    lseek(fd,0,SEEK_SET);
    write(fd,"HELLO\n",sizeof("HELLO\n")-1);
    write(fd,"HELLO1\n",sizeof("HELLO1\n")-1);
    close(fd);//返回0成功，-1失败
    return 0;
}