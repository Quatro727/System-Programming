#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int rfd, wfd, n;
    char buff[10];

    //read a "linux.txt" file -> set fd variable to rfd
    rfd = open("linux.txt", O_RDONLY);
    if (rfd == -1) {
        perror("Open linux.txt");
        exit(1);
    }
    
    //write some shit to "linux.bak" file -> set a variable to wfd
    wfd = open("linux.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open linux.bak");
        exit(1);
    }

    /* perform a low-level read and a perform a write to "linux.bak" */
    
    // read a "linux.txt" file 6bytes each time until read() meet a EOF
    while ((n = read(rfd, buff, 6)) > 0) {
        //write a buff's contents into a "linux.bak" nbytes each time it read
        if (write(wfd, buff, n) != n)
            perror("Write");
    }

    if (n == -1)
        perror("Read");

    close(rfd);
    close(wfd);

    return 0;
}
