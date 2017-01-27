#include <stdio.h>
int main(void)
{
	int m, n, temp, a, b;
	printf("Enter a fraction: ");
	scanf("%d/%d", &m, &n);
	a = m, b = n;
	for (; n > 0; temp = m%n, m = n, n = temp);
	printf("In lowest terms: %d/%d\n", a/m, b/m);
	return 0;
}
