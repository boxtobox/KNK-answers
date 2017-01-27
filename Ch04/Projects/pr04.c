#include <stdio.h>
int main()
{
	int i, o1, o2, o3, o4, o5;
	printf("Enter a number between 0 and 32767: ");
	scanf("%5d", &i);
	o5 = i % 8;
	i /= 8;
	o4 = i % 8;
	i /= 8;
	o3 = i % 8;
	i /= 8;
	o2 = i % 8;
	o1 = i / 8;

	printf("In octal, your number is: %d%d%d%d%d\n", o1, o2, o3, o4, o5);
	return 0;
}
