#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(void)
{
    FILE *fp;
    char *filename = "ex12_test.txt";
    int n;
    printf("Enter a line number: ");
    fscanf(stdin, "%d", &n);
    int len = line_length(filename, n);

    printf("length of line %d: %d\n", n, len);

}

int line_length(const char *filename, int n)
{
    int ch, i = 1, len = 0;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fp) != EOF)) {
        printf("line %d\n", i);
    }
}
