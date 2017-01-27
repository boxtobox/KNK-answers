#include <stdio.h>
int main(void)
{
	char op;
	int num1, num2, denom1, denom2;
	printf("enter two fractions and an operator between them.\n");
	scanf("%d/%d%c%d/%d", &num1, &denom1, &op, &num2, &denom2);

	switch (op)
	{
	case '+':
		printf("add: %d/%d\n", num1*denom2 + num2*denom1, denom1 * denom2);
		break;
	case '-':
		printf("subtract: %d/%d\n", num1*denom2 - num2*denom1, denom1 * denom2);
		break;
	case '*':
		printf("multiply: %d/%d\n", num1 * num2, denom1 * denom2);
		break;
	case '/':
		printf("divide: %d/%d\n", num1 * denom2, denom1 * num2);
		break;
	}
	return 0;
}
