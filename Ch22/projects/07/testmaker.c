/*
this program writes a binary file example for compress_file
this program lacks exception handling.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *filename = "test.txt";
    FILE *fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Error: %s can't be written.\n", filename);
        exit(EXIT_FAILURE);
        }

    int ch;
    int seq;
    int i;
    for(;;) {
        printf("Enter sequence(positive integer). Enter 0 to finish: ");
        scanf("%d", &seq);
        if (seq == 0)
            exit(EXIT_SUCCESS);
        printf("Enter repeated bytes(0-255): ");
        scanf("%hhu", &ch);

        for(i = 0; i < seq; i++) {
            putc(ch, fp);
        }
    }
    fclose(fp);
}
