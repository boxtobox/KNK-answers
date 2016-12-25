/*
(a) Write a program that counts the number of characters in a text file
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch, len = 0;

    if (argc != 2) {
        printf("usage: 04_a filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        len++;
    }
    printf("number of characters in %s: %d\n", argv[1], len);
}
