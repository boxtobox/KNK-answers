#include <stdlib.h>
#include <stdio.h>

int count_periods(const char*);

int main(void)
{
    char *filename = "ex12_test.txt";
    int n;
    n = count_periods(filename);
    printf("There are %d periods in %s\n", n, filename);
    return 0;
}
/* original version
int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    if ((fp = fopen(filename, "r")) != NULL) {
        while (fgetc(fp) != EOF)
            if (fgetc(fp) == '.')
                n++;
        fclose(fp);
    }

    return n;
}
It evaluates fgetc(fp) two times in a while loop, which advances the file position.
Therefore, the if statment tests only ever other characters in the file. To fix this,
we should evaluate fgetc(fp) only once in a while loop.
Also, we should take care of when fp returns NULL pointer(file cannot be opened).
*/
int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF)
        if (ch == '.')
            n++;
    fclose(fp);

    return n;
}
