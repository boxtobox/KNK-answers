#include <stdio.h>

int main(void)
{
	int ar[99][99] = { 0 };
	int i, j, k, n, i_0, j_0;
	printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\n");
	for (;;) {
		printf("Enter size of magic square : ");
		scanf("%d", &n);
		if (n > 0 && n < 100 && (n % 2 == 1))
			break;
	}
	j = (n - 1) / 2 - 1;
	i = 0 + 1;
	for (k = 1; k <= n*n; k++) {
		i--;
		j++;
		if (i >= n)
			i %= n;
		else if (i < 0)
			i += n;
		if (j >= n)
			j %= n;
		else if (j < 0)
			j += n;
		if (ar[i][j] != 0)
		{
			i = i_0 + 1;
			j = j_0;
		}
		ar[i][j] = k;
		i_0 = i;
		j_0 = j;
	}
	printf("\n\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d ", ar[i][j]);
		printf("\n");
	}
	return 0;
}
