#include <stdio.h>
int main(void)
{
	float total, ir, monthly;
	int m;	// number of payments before calculating balance remaining
	printf("Enter amount of loan: ");
	scanf("%f", &total);
	printf("Enter interest rate: ");  // interest rate: 5% --> input 5
	scanf("%f", &ir);
	printf("Enter monthly payment: ");
	scanf("%f", &monthly);
	printf("Enter number of payment: ");
	scanf("%d", &m);

	for (int i = 1; i <= m; i++)
	{
		total = total * (1 + ir / 1200) - monthly;
		printf("Balance remaining after payment %d: %.2f\n", i, total);
	}
	return 0;
}
