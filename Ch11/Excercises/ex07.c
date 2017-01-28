#include <stdio.h>
#include <stdbool.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void) {
	int day_of_year, year, month, day;
	printf("Enter day_of_year:");
	scanf("%d", &day_of_year);
	printf("Enter year: ");
	scanf("%d", &year);
	split_date(day_of_year, year, &month, &day);
	printf("month: %d, day: %d", month, day);
}

void split_date(int day_of_year, int year, int *month, int *day) {
	bool leap;
	int m = 0;
	int day_of_month[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	/* check leap year */
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) leap = true;
			else leap = false;
		}
		else leap = true;
	}
	else leap = false;

	if (leap) day_of_month[1] = 29;
	else day_of_month[1] = 28;

	while (day_of_year - day_of_month[m] >= 1) {
		day_of_year -= day_of_month[m];
		m++;
	}
	*month = m + 1;
	*day = day_of_year;
}
