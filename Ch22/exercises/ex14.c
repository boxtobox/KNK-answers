#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_fgets(char * restrict s, int n, FILE * restrict stream);
int my_fputs(const char * restrict s, FILE * restrict stream);

int main(void)
{
    FILE *fp;
    fp = fopen("ex12_test.txt", "r");
    char str[100];
    fgets(str, 99, fp);
    printf("%s\n", str);

    char *n = my_fgets(str, 99, fp);
    printf("return value of my_fgets: %p\n", n);

    printf("%s\n", str);
    fclose(fp);

    fp = fopen("ex12_test.txt", "a+");

    int n2 = my_fputs("my_fputs testing.", fp);
    printf("return value of my_fputs: %d\n", n2);

    fclose(fp);

}
/* (a) own fgets function */
char *my_fgets(char * restrict s, int n, FILE * restrict stream)
{
    // fgets return NULL if an error occurs or failed to store the string
    int ch, i;
    if ((s = malloc(n)) == NULL)
        return NULL;

    for(i = 0; i < n - 1;) {
        ch = getc(stream);
        if (ch == EOF) {
            if (i == 0)  // EOF or read error occur before storing any characters
                return NULL;
            s[i] = '\0';
            break;
        }
        if (ch == '\n') {
            s[i] = ch;
            s[i + 1] = '\0';
            break;
        }
        s[i] = ch;
    }
    return s;
}

/* (b) own fputs function */
int my_fputs(const char * restrict s, FILE * restrict stream)
{
    // when error occurs, fputs returns EOF
    while(*s)
        if(putc(*s++, stream) < 0)
            return EOF;
    return 0;
}
