#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // char str[30] = "#1,234,567";
    char str[30] = "00#7,654,321abc";
    char *sales_rank;
    int len = strlen(str);

    sales_rank = malloc(len + 1);

    sscanf(str, (str[0] == '#') ? "#%[0123456789,]" : "%*[^#]#%[0123456789,]" , sales_rank);

    printf("%s\n", sales_rank);

}

