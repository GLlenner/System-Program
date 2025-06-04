//dir 文件目录操作
// opendir() readdir() closedir()
//查看/etc目录下的文件

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    DIR* dir;
    /*The  stream is positioned at the first entry in the directory.*/
    /*返回指向的第一个目录项*/
    dir = opendir(".");
    if(dir == NULL)
    {
        perror("opendir()");
        exit(1);
    }
    dirent* dirent;
    /*每次 read dir指针都会向后前进一个目录项,直到为NULL*/
    /*dirent 结构体如下*/
    // struct dirent 
    // {
    //     ino_t          d_ino;       /* Inode number */
    //     off_t          d_off;       /* Not an offset; see below */
    //     unsigned short d_reclen;    /* Length of this record */
    //     unsigned char  d_type;      /* Type of file; not supported
    //                                     by all filesystem types */
    //     char           d_name[256]; /* Null-terminated filename */
    // };
    while((dirent = readdir(dir)) != NULL)
    {   
        if(strcmp(dirent->d_name,".") == 0 || strcmp(dirent->d_name,"..") == 0)
        {
            continue;
        }
        printf("%s\n",dirent->d_name);
    }
    closedir(dir);
    return 0;
}