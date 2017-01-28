#include <stdio.h>

int *find_largest(int a[], int n);
int main(void) {
	int a[6] = { 3,4,5,1,2,7 };
	printf("%d\n", *find_largest(a, 6));
}

int *find_largest(int a[], int n) {
	int i, j = 0, largest = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > largest)
		{
			largest = a[i];
			j = i;
		}
	}
	return &a[j];
}
