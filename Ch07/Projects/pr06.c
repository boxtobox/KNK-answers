#include <stdio.h>
int main(void)
{
	printf("%zu\n%zu\n%zu\n%zu\n%zu\n%zu\n", sizeof(int), sizeof(short), sizeof(long), sizeof(float), sizeof(double), sizeof(long double));
}
// 4 2 4 4 8 12
