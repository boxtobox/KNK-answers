#include <stdio.h>

int main(void)
{
    char ch;
    scanf(" %c", &ch);

    char str[30];
    scanf("%1s", str);
}

/* No. using format string " %c" scanf reads a single nonblack character. it can be stored
   in a char variable. On the other hand, using format string "%1s" scanf reads a string
   which has a single nonblank charater followed by a null character. To store obtained by
   "%1s" format string, we need a character array.

*/
