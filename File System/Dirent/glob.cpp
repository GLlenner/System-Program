//使用glob函数
/*
#include <glob.h>

flags中有一个append参数,可以打开多个文件合到一个 glob_t 结构体中
int glob(const char *pattern, int flags,
                int (*errfunc) (const char *epath, int eerrno),
                glob_t *pglob);

void globfree(glob_t *pglob);
*/
#include <stdio.h>
#include <glob.h>

//实现查找 /etc/a*.conf的全部文件
int main()
{   
    glob();
}