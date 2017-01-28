#include <stdio.h>
#define SIZE 5
int main(void)
{
	int a[SIZE][SIZE], i, j;
	int total = 0;
	for (i = 0; i < SIZE; i++)
	{
		printf("Enter row %d: ", i + 1);
		for (j = 0; j < SIZE; j++)
			scanf("%d", &a[i][j]);
	}

	printf("Row totals: ");
	for (i = 0; i < SIZE; i++)	{
		for (j = 0; j < SIZE;j++)
			total += a[i][j];
		printf("%d ", total);
		total = 0;
	}
	printf("\n");

	printf("Column totals: ");
	for (j = 0; j < SIZE; j++) {
		for (i = 0; i < SIZE; i++)
			total += a[i][j];
		printf("%d ", total);
		total = 0;
	}
	printf("\n");

	return 0;
}
