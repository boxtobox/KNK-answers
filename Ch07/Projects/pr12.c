/* pseudocode
float d1, d2; char op;
assign first num to d1
while NOT next input character is newline    {
assign next num to d2
compute d1(op)d2 and assign result to d1  }
print value of d1
*/
#pragma warning(disable:4996)
#include <stdio.h>
int main(void)
{
	float d1, d2;	// operand 1 and 2
	char op;	// operator
	printf("Enter an expression: ");
	scanf("%f", &d1);		// assign value to d1
	while ((op = getchar()) != '\n')	//if newline is input terminate, else proceed
	{
		scanf("%f", &d2);
		switch (op) {
		case '+':
			d1 += d2;		break;
		case '-':
			d1 -= d2;		break;
		case '*':
			d1 *= d2;		break;
		case '/':
			d1 /= d2;		break;
		default:
			printf("Invalid operator input.\n");	return 0;
		}
	}
	printf("Value of expression: %.2f\n", d1);
	return 0;

}
