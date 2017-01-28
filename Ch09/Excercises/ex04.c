int day_of_year(int month, int day, int year) {
	/* check input year is lunar year*/
	int total = 0, i;
	int days_of_months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) days_of_months[1] = 29;
		}
		else days_of_months[1] = 29;
	}
	for (i = 0; i < month - 1; i++)
		total += days_of_months[i];
	total += day;
	return total;
}
