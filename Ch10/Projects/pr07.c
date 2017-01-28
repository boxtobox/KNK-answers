#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10
#define HEIGHT 4
#define TOTAL_DIGITS 10
#define TOTAL_SEGMENTS 7

const int segments[TOTAL_DIGITS][TOTAL_SEGMENTS] = {
	{ 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 1, 1, 1, 0, 0, 1 },
	{ 0, 1, 1, 0, 0, 1, 1 },
	{ 1, 0, 1, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1 }
};
char digits[HEIGHT][MAX_DIGITS * 4];

/* function prototypes */
void clear_digits_array(void);
/* stores blank characters into all elements of the digits array */

void process_digit(int digit, int position);
/* stores the seven-segment representation of digit into a specified position
in the digits array (positions range from 0 to MAX_DIGITS - 1) */

void print_digits_array(void);
/* displays the rows of the digits array, each on a single line, producing output */

int main(void) {
	int position;
	char ch;
	clear_digits_array();
	position = 0;
	printf("Enter a number: ");
	ch = getchar();
	while (position < 10 && (ch != '\n')) {
		if (ch >= 48 && ch <= 57) {
			process_digit(ch - 48, position);
			position++;
		}
		ch = getchar();
	}
	print_digits_array();
	return 0;
}

void clear_digits_array(void) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < MAX_DIGITS; j++) {
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position) {
	int start = position * 4;
	int i;
	for (i = 0; i < TOTAL_SEGMENTS; i++) {
		if (segments[digit][i] == 1) {
			switch(i) {
				case 0:
					digits[0][start + 1] = '_';	break;
				case 1:
					digits[1][start + 2] = '|';	break;
				case 2:
					digits[2][start + 2] = '|';	break;
				case 3:
					digits[2][start + 1] = '_';	break;
				case 4:
					digits[2][start] = '|';	break;
				case 5:
					digits[1][start] = '|';	break;
				case 6:
					digits[1][start + 1] = '_';	break;
			}
		}
	}
}

void print_digits_array(void) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < MAX_DIGITS * 4; j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}
