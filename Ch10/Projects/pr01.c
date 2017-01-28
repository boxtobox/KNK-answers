/*
1. read characters while input character is not newline.
2. when it reads (, {, [ : push the character into stack.
2. when it reads ), }, ] : pop from the stack and check that the item popped is a matched parenthesis or brace. (if not, NOT MATCHED)
3. when it reads new line, check stack is empty. if if is, MATCHED. if underflow called, NOT MATCHED
4. if overflow called, print the msg 'Stack Overflow' and terminate immediately.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* function prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);

void stack_overflow(void);
void stack_underflow(void);
bool check_brace(char right);
void matched(void);
void not_matched(void);

/* Stack Functions */
void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }
void push(char ch) {
	if (is_full())
		stack_overflow();
	else
		contents[top++] = ch; }
char pop(void) {
	if (is_empty())
		stack_underflow();
	else
		return contents[--top]; }
void stack_overflow(void) {
	printf("Stack Overflow\n");
	exit(EXIT_FAILURE);	// stdlib.h
}
void stack_underflow(void) {
	not_matched();
}
/* End of Stack Functions*/

int main(void) {
	char ch;
	make_empty();
	printf("Enter parentheses and/or brace: ");

	while ((ch = getchar()) != '\n') {
		if (ch == 40 || ch == 123 || ch == 91)
			push(ch);
		else if ((ch == 41 || ch == 125 || ch == 93) && !check_brace(ch))
			not_matched();
	}
	if (is_empty())
		matched();
	else
		not_matched();
}

bool check_brace(char right) {
	char left = pop();
	return (left == 40 && right == 41) || (left == 123 && right == 125) || (left == 91 && right == 93);
}

void matched(void) {
	printf("Parentheses/braces are nested properly.\n");
	exit(EXIT_SUCCESS);
}

void not_matched(void) {
	printf("Parentheses/braces are NOT nested properly.\n");
	exit(EXIT_SUCCESS);
}
