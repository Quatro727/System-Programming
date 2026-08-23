#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int openFile(void);

int main(void)
{
    int fd =0;

    fd = openFile();
    printf("fd = %d\n", fd);
    close(fd);

    //closing fd 0
    close(0);

    //fd 0 is closed above,, so when u open a new file
    //you will allocated a fd 0, because it's smallest number the fd currently got
    fd = openFile();
    printf("fd = %d\n", fd);
    close(fd);

    return 0;
}

int openFile(void)
{
    int fd = open("hello.txt", O_RDWR);
    if(fd == -1) {
        perror("File open");
        exit(1);
    }
    return fd;
}
