#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd, n;
    off_t start, cur_offset;
    char buff[256];

    fd = open("linux.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open linux.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);//define the current offset as start point
    n = read(fd, buff, 255);
    buff[n] = '\0';
    printf("Offset start=%d, Read string=%s, n=%d\n", (int)start, buff, n);

    cur_offset = lseek(fd, 0, SEEK_CUR);//get a current position of offset
    printf("Offset current=%d\n", (int)cur_offset);

    start = lseek(fd, 6, SEEK_SET);//move offset 6bytes from the start point of the file
    n = read(fd, buff, 255);
    buff[n] = '\0';
    printf("Offset start=%d, Read String=%s, n=%d\n", (int)start, buff, n);

    close(fd);

    return 0;
}
