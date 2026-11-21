#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;

    fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Create tmp.bbb");
        exit(1);
    }

    dup2(fd, 1);//using dup2(), copy original fd to fd which has value 1 
                //-> and now when u output to fd1 it output to the file which fd is pointing
                //it doesn't output to standard output anymore
    printf("DUP2: Standatd Output Redirection\n");

    close(fd);

    return 0;
}
