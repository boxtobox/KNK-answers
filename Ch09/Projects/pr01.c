#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);

int main(void) {
	int a[N], i;
	printf("Enter %d numbers to be sorted: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	selection_sort(a, N);
	printf("In sorted order: ");
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void selection_sort(int a[], int n) {
	int i, max = a[0], max_index = 0;
	int temp;
	if (n == 1)	return;
	for (i = 1; i < n; i++) {
		if (a[i] > max)		{
			max = a[i];
			max_index = i;
		}
	}
	temp = a[n - 1];
	a[max_index] = temp;
	a[n - 1] = max;
	selection_sort(a, n - 1);
}
