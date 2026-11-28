/* Binary I/O - fwrite() */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *fileName = "binary.bin";                                  //specified a file name as a "binary.bin"
    int data[5] = {10, 20, 30, 40, 50};                             //data set for being written
    FILE *fp = NULL;

    //open the file in "binaray write" mode
    if ( !(fp = fopen(fileName, "wb")) ) {
        fprintf(stderr, "Faile to open the file - %s\n", fileName);
        exit(1);
    }
    
    //write a data in file pointed by fp
    size_t i = fwrite(data, sizeof(int), 5, fp);
    printf("Success to write %d objects.\n", i);

    fclose(fp);

    return 0;
}
