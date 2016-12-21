// ex7.c

#include <stdio.h>

int main(void)
{
    int i, j, n;
    float x;
    n = scanf("%d%f%d", &i, &x, &j);

    printf("i: %d, j: %d, x: %f, n: %d\n", i, j, x, n);
}

/*

(a) 10 20 30
i: 10, j: 30, n: 3, x: 20.000000

(b) 1.0 2.0 3.0
i: 1, j: 2, n: 3, x: 0.000000

(c) 0.1 0.2 0.3
i: 0, j:0, n: 3, x: 0.100000

(d) .1 .2 .3
i: 59, j: it keeps changing, n: 0, x: 0.000000
scanf does not assign any value to either of i, j, or x.
*/
