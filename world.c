#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv) {
    char *buf;
    int n;
    int fd;
    int buf_size;
    if ((fd = open(*(argv + 1), 0)) < 0) {
        printf("could not open(%s)\n", *(argv + 1));
        return -1;
    }
    buf_size = 1024 * 1024;
    buf = malloc(buf_size);
    n = read(fd, buf, buf_size);
    if (n <= 0) {
        return 0;
    }
    buf[n] = 0;
    printf("%s", buf);
    return 0;
}
