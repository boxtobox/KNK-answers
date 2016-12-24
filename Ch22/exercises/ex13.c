#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);
void print_file_line_len(const char *filename);  // for checking contents of the file

int main(void)
{
    char *filename = "ex12_test.txt";
    int n;
    printf("enter a line number: ");
    fscanf(stdin, "%d", &n);

    int len = line_length(filename, n);
    printf("length of line %d: %d\n", n, len);

    print_file_line_len(filename);
    return 0;
}

int line_length(const char *filename, int n)
{
    int ch, line, len = 0;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (line = 1; line < n; ) {
        ch = fgetc(fp);
        if (ch == EOF) {
            fclose(fp);
            return 0;
        }
        if (ch == '\n')
            line++;
    }
    // we now reached line n
    for(;;) {
        ch = fgetc(fp);
        if (ch == EOF || ch == '\n') {
            fclose(fp);
            return len;
        }
        len++;
    }
}

void print_file_line_len(const char *filename)
{
    int ch, line = 1, len = 0;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("%02d: ", line);
    for(;;) {
        ch = fgetc(fp);
        if (ch == EOF) {
            printf(" (len: %d)\n", len);
            fclose(fp);
            return;
        }
        else if (ch == '\n') {
            printf(" (len: %d)\n", len);
            line++;
            printf("%02d: ", line);
            len = 0;
        }
        else {
            printf("%c", ch);
            len++;
        }
    }
    fclose(fp);
}
