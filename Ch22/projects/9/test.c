// test
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10000

struct test{
int abc;
double def;};

int main(void)
{
    struct test *yo;
    yo = malloc(sizeof(*yo) * 100);
    int i;
    for(i = 0; i < 50; i++) {
        (yo + i)->abc = i * 2;
        (yo + i)->def = (double) 3.14 * i;
    }

    for(i = 0; i < 30; i++) {
        printf("%d\t%f\n", (yo+i)->abc, (yo+i)->def);
    }
}

