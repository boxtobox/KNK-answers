#include <stdio.h>
int main()
{
	int m1, d1, y1, m2, d2, y2, m0, d0, y0;
	int compare; // -1: first date is earlier, 0: two dates are same, 1: second date is earlier
	printf("omitted number in front of yy is assumed to be 20\n");
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);

	for (;;) {
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &m0, &d0, &y0);
		if ((m0 == 0) && (d0 == 0) && (y0 == 0))
			break;
		else
			m2 = m0, d2 = d0, y2 = y0;
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
	}
	switch (compare)
	{
	case -1: case 0:
		printf("%d/%d/%.2d is earliest date\n", m1, d1, y1);
		break;
	case 1:
		printf("%d/%d/%.2d is earliest date\n", m2, d2, y2);
		break;
	}
	return 0;
}
