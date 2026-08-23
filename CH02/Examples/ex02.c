#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;

    //open  the file using OR operation(|) 
    fd = open("hello.txt", O_CREAT | O_EXCL, 0644);
    if(fd == -1) {
        //error code is stored in errno.
        //errno variable is defined in error.h file
        //you can acces by 'extern int errno;'
        perror("EXCL");
        exit(1);
    }
    close(fd);

    return 0;
}
