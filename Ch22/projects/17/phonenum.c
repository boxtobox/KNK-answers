/*
Write a program that reads a series of phone numbers from a file
(file name is obatined from the command line)
and displays them in a standard format.
assumption: each line contains 10 digits, possibly mixed with other characters
characters should be ignored
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DIGITS 10

int main(int argc, char *argv[])
{
    FILE *fp;
    char phone_number[DIGITS+1];
    int ch;

    if (argc != 2) {
        fprintf(stderr, "usage: phonenum filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            phone_number[DIGITS] = '\0';
            printf("(%.3s) %.3s-%.4s\n", phone_number, phone_number+3, phone_number+6);
            i = 0;
        }
        if (isdigit(ch))
            phone_number[i++] = ch;
    }

    fclose(fp);
    return 0;
}
