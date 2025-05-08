#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    char *filename = NULL;
    int verbose = 0;

    while ((opt = getopt(argc, argv, "f:v")) != -1) {
        switch (opt) {
        case 'f':
            filename = optarg;  // 获取 -f 后面的参数
            break;
        case 'v':
            verbose = 1;        // 开启 verbose 模式
            break;
        default:
            fprintf(stderr, "Usage: %s [-v] [-f filename]\n", "niaho");
            return 1;
        }
    }

    printf("filename = %s\n", filename);
    printf("verbose = %d\n", verbose);
    return 0;
}
