#include <stdio.h>
#define SIZE_A (int) (sizeof(a) / sizeof(a[0]))
int main(void)
{
	int a[10], i;
	printf("Enter %d numbers: ", SIZE_A);
	for (i = 0; i < SIZE_A; i++)
		scanf("%1d", &a[i]);
	printf("In reverse order: ");
	for (i = SIZE_A; i > 0; i--)
		printf("%d ", a[i-1]);
	printf("\n");
	return 0;
}
