#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("请输入一行文本：\n");

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        perror("getline");
        free(line);
        return 1;
    }

    printf("你输入的是：%s", line);

    free(line);
    return 0;
}
