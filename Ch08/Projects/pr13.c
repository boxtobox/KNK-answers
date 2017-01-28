#include <stdio.h>
int main(void)
{
	char first_name, last_name[20];
	int length, i = 0;
	char c;
	printf("Enter a first and last name: ");
	first_name = getchar();
	while (getchar() != ' ');
	while ((c = getchar()) != '\n') {
		last_name[i] = c;
		i++;
	}
	length = i;
	printf("You entered the name: ");
	for (i = 0; i < length; i++)
		printf("%c", last_name[i]);
	printf(", %c.\n", first_name);
	return 0;
}
