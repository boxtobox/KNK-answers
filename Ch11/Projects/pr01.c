#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
int main(void) {
	int twenties, tens, fives, ones, dollars;
	printf("Enter Dollars: ");
	scanf("%d", &dollars);
	pay_amount(dollars, &twenties, &tens, &fives, &ones);
	printf("Twenties: %d, Tens: %d, Fives: %d, Ones: %d\n", twenties, tens, fives, ones);
	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens,
	int *fives, int *ones) {
	*twenties = dollars / 20;
	dollars %= 20;
	*tens = dollars / 10;
	dollars %= 10;
	*fives = dollars / 5;
	*ones = dollars % 5;
}
