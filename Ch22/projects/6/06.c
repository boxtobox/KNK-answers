#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: 06 filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch = 0, line = 0, i;
    char chars[11];

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    for(; ch != EOF;) {
        if ((ch = getc(fp)) != EOF) {
            printf("%6d  ", line * 10);
            ungetc(ch, fp);
        }

        for(i = 0; i < 10; i++) {
            if ((ch = getc(fp)) == EOF) {
                break;
            }
            printf("%.2X ", ch);
            if (!isprint(ch))
                ch = '.';
            chars[i] = ch;
        }
        chars[i] = '\0';
        for( ; i < 10; i++) // trick to fill the gaps when i is less than 9 when cursor reached EOF
            printf("   ");
        line++;

        printf(" %s\n", chars);
    }

    fclose(fp);
}
