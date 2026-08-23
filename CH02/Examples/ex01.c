#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;
    mode_t mode;//when creating a new file, u must set a permission value.

    //permission value setting using flags -> it's same as using 644
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fd = open("hello.txt", O_CREAT, mode);
    if(fd == -1) {
        perror("Creat");
        exit(1);
    }
    close(fd);

    return 0;
}
