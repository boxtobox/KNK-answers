#include <stdio.h>
#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void) {
	int a[N], *p;
	printf("Enter %d numbers to be sorted: ", N);
	for (p = a; p < a + N; p++)
		scanf("%d", p);
	quicksort(a, a, a + N - 1);

	printf("In sorted order: ");
	for (p = a; p < a + N; p++)
		printf("%d ", *p);
	printf("\n");

	return 0;
}

void quicksort(int a[], int *low, int *high) {
	int *middle;
	//	low, high is index of elements
	if (low >= high) return;	// if lowest index >= highest index, end recursion
	middle = split(a, low, high);	// find middle index
	quicksort(a, low, middle - 1);	// call itself recursively from low to middle-1
	quicksort(a, middle + 1, high);	// call itself recursively from middle+1 to high
}

int *split(int a[], int *low, int *high) {
	int part_element = *low;
	for (;;) {
		while (low < high && part_element <= *high)	// high is on the right side of array, high-- and check again
			high--;
		if (low >= high) break;
		*low++ = *high;	// high is on the wrong side, switch low and high, and low++ and check low is on the right side

		while (low < high && *low <= part_element)	// low is on the right side of array, low++ and check again
			low++;
		if (low >= high) break;
		*high-- = *low;	//	low is on the wrong side, switch low and high, and high-- and check high is on the right side
	}

	*high = part_element;	// after switching is all done, return high as new part_element
	return high;
}
