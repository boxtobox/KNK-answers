#include <stdio.h>
int main()
{
	int m1, d1, y1, m2, d2, y2;
	int compare; // -1: first date is earlier, 0: two dates are same, 1: second date is earlier
	printf("year is regarded as 20XX\n");
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);

	if (y1 < y2)
		compare = -1;
	else if (y1 == y2)
	{
		if (m1 < m2)
			compare = -1;
		else if (m1 == m2)
		{
			if (d1 < d2)
				compare = -1;
			else if (d1 == d2)
				compare = 0;
			else
				compare = 1;
		}
		else compare = 1;
	}
	else
		compare = 1;

	switch (compare)
	{
	case -1:
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
		break;
	case 0:
		printf("%d/%d/%.2d is same as %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
		break;
	case 1:
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
		break;
	}


	return 0;
}
