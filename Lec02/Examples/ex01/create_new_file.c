#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;
    mode_t mode;//in case of creating a new file, to set a permission value for it.
    
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; //set a file's permission value by bit operations -> permission value = 644

    fd = open("hello.txt", O_CREAT, mode);
    if (fd == -1) {
        perror("Create");
        exit(EXIT_FAILURE);
    }
    close(fd);

    return 0;
}
