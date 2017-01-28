#include <stdio.h>

void create_magic_square(int n, int magic_square[99][99]);
void print_magic_square(int n, int magic_square[99][99]);
int main(void) {
	int n;
	int board[99][99] = { 0 };
	printf("Enter the size of square(odd number, between 1 and 99: ");
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("You can't enter even number.\n");
		return 0;
	}
	create_magic_square(n, board);
	print_magic_square(n, board);
	return 0;
}
void create_magic_square(int n, int magic_square[99][99]) {
	int i = 0, j = (n - 1) / 2, k, new_i, new_j;
	for (k = 1; k <= n*n; k++) {
		magic_square[i][j] = k;
		new_i = (i == 0) ?  n - 1 : i - 1;
		new_j = (j == n - 1) ?  0 : j + 1;
		if (magic_square[new_i][new_j] != 0) {
			new_i = (i == n - 1) ? 0 : i + 1;
			new_j = j;
		}
		i = new_i; j = new_j;
	}
}
void print_magic_square(int n, int magic_square[99][99]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%4d", magic_square[i][j]);
		printf("\n");
	}
}
