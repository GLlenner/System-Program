/*使用grtpwuid获取grt用户的UID*/
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
    if(argc < 2)
    {
        perror("Using");
        exit(1);
    }

    /*
    struct passwd *getpwnam(const char *name);
    struct passwd *getpwuid(uid_t uid);
    返回值是一个 passwd结构体指针
    */
    struct passwd* pw;
    pw = getpwuid(1000);
    printf("uid:1000 -> name:%s\n",pw->pw_name);
    return 0;
}

/*通常用户信息会存储在 /etc/passwd 文件当中*/
/*
/etc/passwd 是类 Unix 系统中的一个 用户账户信息数据库文件
用户名 :密码占位符:用户ID :组ID    :备注     :主目录      :默认Shell
vida   :x        :1000  :1000    :Vida,,,  :/home/vida :/bin/bash
*/