/* Binary I/O - fread() */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int buff[5] = {0};
    FILE *fp = fopen("binary.bin", "rb");                               //specifyt a file

    if ( !fp ) {
        fprintf(stderr, "Fail to open the file - %s\n", "binary.bin");
        exit(1);
    }

    size_t i = fread(buff, sizeof(int), 5, fp);                         //read a file pointed by fp using fread()
    printf("Success to read %d object(s).\n", i);

    for (int i = 0; i < 5; i++)                                         //print a data written in file pointed by a fp 
        printf("%d ", buff[i]);
    printf("\n");

    fclose(fp);

    return 0;
}
