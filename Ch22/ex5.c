// ex5

/*
difference between the printf conversion specifiers
%.4d and %04d ?

.4, precision is minimum number of digits
4, minimum field width is minimum number of characters to be shown
when a nonnegative number is displayed, two conversion specification is same.
however, when negative number is displayed, %.4d displays 4 digits and - sign
and %04d displays 3 digits and - sign if it's enough to represent the number.
*/

#include <stdio.h>

int main(void)
{
    int i1 = 1234;
    int i2 = -123;

    printf("%.4d\n", i2); // -0123
    printf("%04d\n", i2); // -123
}
