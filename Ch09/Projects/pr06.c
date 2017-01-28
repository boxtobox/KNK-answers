#include <stdio.h>
#include <math.h>

double poly(double x);
int main(void) {
	double x;
	printf("Enter value of x: ");
	scanf("%lf", &x);
	printf("%f\n", poly(x));
	return 0;
}
double poly(double x) {
	return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - x*x + 7 * x - 6;
}
