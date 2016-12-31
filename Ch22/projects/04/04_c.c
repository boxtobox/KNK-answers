/*
(c) Write a program that counts the number of lines in a text file.
lines = number of '\n' + 1
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch, lines = 0;

    if (argc != 2) {
        printf("usage: 04_c filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: %s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n')
            lines++;
    }

    lines = lines + 1;
    printf("%d line(s) in %s\n", lines, argv[1]);
    fclose(fp);
    return 0;
}

