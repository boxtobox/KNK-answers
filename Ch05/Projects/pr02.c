#include <stdio.h>

int main()
{
	int h, m;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h, &m);
        if (h > 23 || h < 0) {
            printf("Invalid Input\n");
            return 1;
        }

	printf("Equivalent 12-hour time: ");
	if (h == 0)
		printf("12:%.2d AM\n", m);
	else if (0 < h && h <= 11)
		printf("%d:%.2d AM\n", h, m);
	else if
		(13 <= h && h <= 23)
		printf("%d:%.2d PM\n", h - 12, m);
	else if (h == 12)
		printf("%d:%.2d PM\n", h, m);

	return 0;

}
