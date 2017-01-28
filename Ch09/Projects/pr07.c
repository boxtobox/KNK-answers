#include <stdio.h>

double power2(double x, int n);
int main(void) {
	double x;
	int n;
	printf("Input double x, int n: ");
	scanf("%lf %d", &x, &n);

	printf("value of x^n: ");
	printf("%f\n", power2(x, n));
	return 0;
}
double power2(double x, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power2(x, n / 2) * power2(x, n / 2);
	else
		return x * power2(x, n - 1);
}
