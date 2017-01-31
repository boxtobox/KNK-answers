#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const char months[][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

void convert(const char *str, char *date, int n) {
	int m, d, y;
	char temp[10], *p = str, *s = temp;
	while (*p != '/')
		*s++ = *p++;
	*s = 0, p++;
	m = atoi(temp);
	if (m < 1 || m>12)
	{
		printf("Month must be between 1 and 12.\n");
		exit(1);
	}
	s = temp;

	while (*p != '/')
		*s++ = *p++;
	*s = 0, p++;
	d = atoi(temp);
	if (d < 1 || d>31)
	{
		printf("Day must be between 1 and 31.\n");
		exit(1);
	}
	s = temp;
	while (*p != '\n')
		*s++ = *p++;
	*s = 0;
	y = atoi(temp);

	sprintf(date,"You entered the date %s %d, %d", months[m-1], d, y);
}

int main(void) {
	char str[100];
	char date[100];
	printf("Enter a date (mm/dd/yyyy): ");
	fgets(str, 100, stdin);
	convert(str, date, 100);
	printf("%s\n", date);
}
