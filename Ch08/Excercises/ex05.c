#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int fib[40] = { 0, 1 };
	int i;
	for (i = 2; i < 40; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
}
