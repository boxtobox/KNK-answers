/*
(b) Write a program that counts the number of words in a text file
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_words(FILE *fp);
// return 1 if it consumed a word from fp. If it failed to read a word, return 0.
int main(int argc, char *argv[])
{
    FILE *fp;
    int words = 0;

    if (argc != 2) {
        printf("usage: 04_b filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: %s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*
    while((fscanf(fp, "*%s", NULL)) == 1)
        words++;
    it would be nice if it were legal to use an expression like above
    */

    while (read_words(fp))
        words++;
    fclose(fp);
    printf("%d word(s) in %s\n", words, argv[1]);
}

int read_words(FILE *fp)
{
    int ch;
    int word_read = 0; // a flag which is set when a valid word is read.
    for(;;) { // skip a sequece of white-space characters,
              // stop before the first non-white-space character
        if ((ch = getc(fp)) == EOF)
            return 0;
        if (!isspace(ch)) {
            ungetc(ch, fp);
            break;
        }
    }

    for(;;) { // skips a sequence of non-white-space characters,
              // stops before the first white-space character
        if ((ch = getc(fp)) == EOF)
            if (word_read)
                return 1;
            else
                return 0;

        if (isspace(ch)) {
            ungetc(ch, fp);
            break;
        }
        word_read = 1;
    }

    return 1;
}
