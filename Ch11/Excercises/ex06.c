#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
	int largest, second_largest;
	int a[] = { 10,9,8,7,6,5,4,3,2,1,13,15 };
	find_two_largest(a, 12, &largest, &second_largest);
	printf("%d %d\n", largest, second_largest);
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
	int first, second, i;
	if (a[0] > a[1])
		first = a[0], second = a[1];
	else
		first = a[1], second = a[0];

	for (i = 2; i < n; i++) {
		if (a[i] > first) {
			second = first;
			first = a[i]; }
		else if (a[i] > second)
			second = a[i];
	}
	*largest = first;
	*second_largest = second;
}
