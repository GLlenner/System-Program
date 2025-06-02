/*
全局变量 environ 存放了当前环境的环境变量 extern char **environ;
char *getenv(const char *name); 获取环境变量
int setenv(const char *name, const char *value, int overwrite);
*/

/*环境变量相关函数*/
#include <stdio.h>
#include <stdlib.h>
extern char** environ;
int main()
{   
    for(int i = 0;environ[i] != NULL;i++)
    {
        puts(environ[i]);
    }
    puts("\n");
    puts(getenv("PATH"));
    return 0;
}