//实现文件操作 cp 

#include<stdio.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage: ./mycopy <file1> <file2>");
        exit(1);
    }
    FILE* sour = nullptr;
    FILE* dist = nullptr;
    sour = fopen(argv[1],"r");
    if(sour == nullptr)
    {   
        perror("fopen()");
        exit(1);
    }
    dist = fopen(argv[2],"w");
    if(dist == nullptr)
    {
        fclose(sour);
        perror("fopen()");
        exit(1);
    }
    int ch  = 0;
    //fgetc 和 fputc 函数
    //int fgetc(FILE *_File) 返回的是 int 值, 失败时返回EOF
    /*
    while((ch = fgetc(sour)) != EOF)
    {
        fputc(ch,dist);
    }
    */
    
    //fgets 和 fputs 函数
    //char *fgets(char *__restrict__ _Buf, int _MaxCount, FILE *__restrict__ _File)
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), sour))
    {
        fputs(buffer, dist);
    }
    
    fclose(sour);
    fclose(dist);
    return 0;
}