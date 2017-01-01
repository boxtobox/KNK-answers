/*
write a program that converts a UNIX text file to a Windows text file
difference between Windows and UNIX text files
1. end-of-line marker.
In Windows: '\x0d'(CR) followed by '\x0a'(LF)
In UNIX: single '\x0a'(LF)
2. end-of file marker.
In Windows: it may contain end-of-file marker '\x1a'
In UNIX: it doesn't have any end-of-file marker
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp_in, *fp_out;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "This program converts a UNIX text file to a Windows text file\n"
                "usage: 19_b infile outfile");
        exit(EXIT_FAILURE);
    }

    if ((fp_in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp_out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp_in)) != EOF) {
        if (ch == '\x0a') {
            printf("meet newline\n");
            putc('\x0d', fp_out);
            putc('\x0a', fp_out);
        }
        else
            putc(ch, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

