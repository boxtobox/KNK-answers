/* fupper.c
This program converts all letters in a file to upper case.
Characters other than letters shouldn't be changed.
usage: fupper file
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    if (argc < 2) {
        printf("usage: fupper filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF)
        putchar(toupper(ch));

    fclose(fp);
    return 0;
}
