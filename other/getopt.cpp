#include <stdio.h>
#include <unistd.h>  // 提供 getopt()
#include <stdlib.h>  // 提供 atoi()

int main(int argc, char *argv[]) {
    int opt;
    char *name = NULL;
    int age = -1;

    while ((opt = getopt(argc, argv, "n:a:")) != -1) {
        switch (opt) {
            case 'n':
                name = optarg;
                break;
            case 'a':
                age = atoi(optarg);
                break;
            case '?':
                printf("用法: %s -n <name> -a <age>\n", argv[0]);
                return 1;
        }
    }

    if (name && age != -1) {
        printf("你好，%s，你今年 %d 岁。\n", name, age);
    } else {
        printf("请输入名字和年龄！\n");
        printf("用法: %s -n <name> -a <age>\n", argv[0]);
    }

    return 0;
}
