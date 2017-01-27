#include <stdio.h>
int main(void)
{
	char first;
	char last;
	printf("Enter a first and last name: ");
	while ((first = getchar()) == ' ');	// assign first letter of first name in variable first
	while ((last = getchar()) != ' ');	// skip all letters before blanks(first name)
	while ((last = getchar()) == ' ');	// skip all blanks
	printf("%c", last);	// print first letter of last name
	last = getchar();
	while (last != ' ' && last != '\n')
	{
		printf("%c", last);
		last = getchar();
	}
	printf(", %c.\n", first);
	return 0;
}
