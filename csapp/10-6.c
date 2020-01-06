#include "csapp.h"

//open()返回当前没有打开的最小描述符
int main() {
    int fd1 = open("foo.txt", O_RDONLY, 0);
    int fd2 = open("bar.txt", O_RDONLY, 0);
    printf("%d\n", fd2);
    close(fd2);
    fd2 = open("baz.txt", O_RDONLY, 0);
    printf("%d\n", fd2);
    exit(0);
}