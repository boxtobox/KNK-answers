/*
fcat.c
this program concatenates any number of files by writing them to
standard output, one after the other, with no break between files.
names of files will be provided in command line by user.

usage: fcat f1.c f2.c f3.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, ch;

    if (argc < 2) {
        printf("usage: fcat filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "error: %s can't be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
    fclose(fp);

    for (i = 1; i <argc; i++) {
        fp = fopen(argv[i], "r");
        while((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

}
