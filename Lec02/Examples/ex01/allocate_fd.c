#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int openFile(void);

int main(void)
{
    int fd = 0;

    fd = openFile();
    printf("fd = %d\n", fd);
    close(fd);

    close(0);//close the fd 0-> close stdin
    
    //fd will get a fd #0 -> becuz just before, we close the fd #0
    fd = openFile();
    printf("fd = %d\n", fd);
    close(fd);

    return 0;
}
int openFile(void)
{
    int fd;
    
    fd = open("hello.txt", O_RDWR);
    if (fd == -1) {
        perror("File open");
        exit(1);
    }
    return fd;
}


