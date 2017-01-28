#include <stdio.h>

int sum_array(const int *a, int n);
int main(void) {
	int a[] = { 1,3,5,7,9 };
	printf("%d\n", sum_array(a, 5));
}

int sum_array(const int *a, int n) {
	int *p, sum;
	sum = 0;
	for (p = a; p < a + n; p++)
		sum += *p;
	return sum;
}

