/*
run-length encoding, simple technique for compressing the contents of a file
This technique compresses a file by replacing sequences of identical bytes by
a pair of bytes: a repetition count followed by a byte to be repeated.

original file:
46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20

compressed file:
01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp_orig, *fp_comp;
    int ch, ch_last, ch_count;

    if (argc != 2) {
        fprintf(stderr, "Usage: compress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp_orig = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *new_name = malloc(strlen(argv[1]) + 4);

    strcpy(new_name, argv[1]);
    strcat(new_name, ".rle");

    if ((fp_comp = fopen(new_name, "wb")) == NULL) {
        fprintf(stderr, "Error: can't write %s\n", new_name);
        exit(EXIT_FAILURE);
    }

    printf("compressed file name is %s\n", new_name);

    if ((ch_last = getc(fp_orig)) == EOF) {
        fprintf(stderr, "Empty file\n");
        exit(EXIT_FAILURE);
    }
    ch_count = 1;
    while((ch = getc(fp_orig)) != EOF) {
        if (ch == ch_last) {
            ch_count++;
        }
        else {
            putc(ch_count, fp_comp);
            putc(ch_last, fp_comp);
            ch_count = 1;
        }
        ch_last = ch;
    }
    putc(ch_count, fp_comp);
    putc(ch_last, fp_comp);
    fclose(fp_orig);
    fclose(fp_comp);
    return 0;
}
