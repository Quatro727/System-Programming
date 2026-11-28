/* String Based I/O */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *rfp, *wfp;
    char buff[BUFSIZ];      //BUFSIZ is defined in the stdio.h

    printf("BUFSIZ=%d\n", BUFSIZ);

    if ((rfp = fopen("hello.txt", "r")) == NULL) {
        perror("fopen: hello.txt");
        exit(1);
    }

    if ((wfp = fopen("hello.out", "a")) == NULL) {
        perror("fopen: hello.out");
        exit(1);
    }

    while (fgets(buff, BUFSIZ, rfp) != NULL) {
        fputs(buff, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}

