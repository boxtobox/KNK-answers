/*
Write a program that reads integers from a text file whose name is given as a command-line
argument. Each line of the file may contain any number of integers (including none)
separated by one or more spaces. Have the program display the largest number in the file,
the smallest number, and the median. If the file contains an even number of integers,
display average of two numbers in the middle(rounded down). You may assume that the file
contains no more than 10,000 integers.
*/

#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_INTS 10000

int compare_int(const void *a, const void *b);
int main(int argc, char *argv[])
{
    FILE *fp;
    int num, numbers[NUM_OF_INTS];
    int i = 0, n, len;
    int min, med, max;

    if (argc != 2) {
        fprintf(stderr, "usage: readnum filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((n = fscanf(fp, "%d", &num)) == 1) {
        numbers[i++] = num;
    }
    printf("read %d numbers\n", i);
    len = i;

    qsort(numbers, len, sizeof(int), compare_int);
    min = numbers[0], max = numbers[len-1];
    if (len % 2 == 0)
        med = (numbers[len/2 - 1] + numbers[len/2]) / 2;
    else
        med = numbers[len/2];

    printf("largest number: %d, smallest number: %d, median: %d\n", max, min, med);

    fclose(fp);
    return 0;
}

int compare_int(const void *a, const void *b)
{
    const int *num1 = a;
    const int *num2 = b;
    if (*num1 < *num2)
        return -1;
    else if (*num1 == *num2)
        return 0;
    else
        return 1;
}
