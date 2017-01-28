#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

/**** STACK ****/

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
	top = 0;
}

bool is_empty(void) {
	return top == 0;
}

bool is_full(void) {
	return top == STACK_SIZE;
}

void stack_underflow(void) {
	printf("Not enough operands in expression.\n");
	exit(EXIT_FAILURE);
}

void stack_overflow(void) {
	printf("Expression is too complex.\n");
	exit(EXIT_FAILURE);
}

void push(int i) {
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

int pop(void) {
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

/**** END OF STACK ****/

/* function prototypes */
void read_expression(void);
void read_operand(int i);
void read_operator(char ch);
void print_result(void);

int main(void) {
	read_expression();
	return 0;
}

void read_expression(void) {
	char ch;
	make_empty();
	printf("Enter an RPN expression: ");
	while (1) {
		scanf(" %c", &ch);
		if (ch == 'q' || ch == 'Q')
			exit(EXIT_SUCCESS);
		else if (ch == '=')
			print_result();
		else if (ch >= 48 && ch <= 57)
			read_operand(ch - 48);
		else
			read_operator(ch);
	}
}
void read_operand(int i) {
	push(i);
}

void read_operator(char ch) {
	int i, j, result;
	j = pop();
	i = pop();
	switch (ch) {
	case '+':	result = i + j;		push(result); break;
	case '-':	result = i - j;		push(result); break;
	case '*':	result = i * j;		push(result); break;
	case '/':	result = i / j;		push(result); break;
	default:	printf("input error.\n");	exit(EXIT_FAILURE);
	}
}

void print_result() {
	int result;
	result = pop();
	printf("Value of expression: %d\n", result);
	read_expression();
}
