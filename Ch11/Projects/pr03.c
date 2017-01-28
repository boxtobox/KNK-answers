#include <stdio.h>

void reduce(int numerator, int denominator,
	int *reduced_numerator, int *reduced_denominator);
int gcd(int i, int j);

int main(void) {
	int i, j;
	printf("Enter a fraction (a/b): ");
	scanf("%d/%d", &i, &j);
	int reduced_numerator, reduced_denomiator;
	reduce(i, j, &reduced_numerator, &reduced_denomiator);
	printf("%d/%d\n", reduced_numerator, reduced_denomiator);
}

void reduce(int numerator, int denominator,
	int *reduced_numerator, int *reduced_denominator) {
	int d = gcd(numerator, denominator);
	*reduced_numerator = numerator / d;
	*reduced_denominator = denominator / d;
}

int gcd(int m, int n) {
	int temp;
	if (m < n) {
		temp = m;
		m = n;
		n = temp;
	}
	while (n > 0) {
		temp = m%n;
		m = n;
		n = temp;
	}
	return m;
}
