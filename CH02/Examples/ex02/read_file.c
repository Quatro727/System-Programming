#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd, n;
    char buf[10];

    fd = open("linux.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open");
        exit(1);
    }

    //read 5byte from linux.txt and store in buf
    n = read(fd, buf, 5);
    if (n == -1) {
        perror("Read");
        exit(1);
    }

    buf[n] = '\0';//make a array of char to sting by adding null character next to a last character
    printf("n=%d, buf=%s\n", n, buf);
    close(fd);

    return 0;
}
