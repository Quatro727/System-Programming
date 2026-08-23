#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main(void)
{
    if(access("test.txt", R_OK) == -1) {
        perror("test.txt");
        exit(1);
    }
}
