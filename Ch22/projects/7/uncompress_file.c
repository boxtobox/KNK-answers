/*
This program reverses the compression performed by the compress_file
program. The uncompress_file command will have the form

uncompress_file compressed-file

compressed-file should have the extension .rle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *str_right(const char *str, int right, bool lower);


int main(int argc, char *argv[])
{
    FILE *fp_comp, *fp_uncm;
    int ch, ch_count;
    char *ext, *new_name;

    if (argc != 2) {
        fprintf(stderr, "Usage: uncompress_file filename\n");
        exit(EXIT_FAILURE);
    }

    ext = str_right(argv[1], 3, true);
    if (strcmp(ext, "rle")) {
        fprintf(stderr, "Error: filename must have .rle extension.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp_comp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: %s cannot be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    new_name = malloc(strlen(argv[1]) - 4 + 1);
    strncpy(new_name, argv[1], strlen(argv[1]) - 4);

    if ((fp_uncm = fopen(new_name, "wb")) == NULL) {
        fprintf(stderr, "Error: %s cannot be written.\n", new_name);
    }

    while((ch = getc(fp_comp)) != EOF) {
        ch_count = ch;
        if ((ch = getc(fp_comp)) == EOF) {
            fprintf(stderr, "Error: compressed file is not paired\n");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < ch_count; i++)
            putc(ch, fp_uncm);
    }
    printf("work complete. new file name is %s\n", new_name);
}

char *str_right(const char *str, int right, bool lower)
{
    char *ret_str;
    int max_len = strlen(str);

    if (right > max_len) {
        printf("Error: Input exceeds the length of source string.\n");
        return NULL;
    }
    if ((ret_str = malloc(right + 1)) == NULL) {
        printf("Error: malloc failed.\n");
        return NULL;
    }

    if (lower) {
        int i;
        for(i = 0; i < right; i++) {
            ret_str[i] = tolower(str[max_len - right + i]);
        }
        ret_str[i] = '\0';
    }

    else {
        strncpy(ret_str, str + max_len - right, right);
        ret_str[right] = '\0';
    }
    return ret_str;
}
