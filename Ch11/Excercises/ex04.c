#include <stdio.h>

void swap(int *p, int *q);

int main(void) {
	int i = 3, j = 5;
	swap(&i, &j);
	printf("%d %d\n", i, j);
}

void swap(int *p, int *q) {
	int temp = *q;
	*q = *p;
	*p = temp;
}
