#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

/**** STACK ****/

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = &contents[0];

void make_empty(void) {
	*top_ptr = 0;
}

bool is_empty(void) {
	return top_ptr == &contents[0];
}

bool is_full(void) {
	return top_ptr == &contents[STACK_SIZE];
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
		*top_ptr++ = i;
}

int pop(void) {
	if (is_empty())
		stack_underflow();
	else
		return *--top_ptr;
}

/**** END OF STACK ****/

/* function prototypes */
void read_expression(char *expr);
void read_operator(char ch);
int evaluate_RPN_expression(const char *expression);

int main(void) {
	char str[400];
	int value;
	read_expression(str);
	value = evaluate_RPN_expression(str);
	printf("%d\n", value);
	return 0;
}

void read_expression(char *expr) {
	char ch, *p = expr;
	ch = getchar();
	if (toupper(ch) == 'Q')
		exit(0);
	while (ch != '\n') {
		if (ch != ' ')
			*p++ = ch;
		ch = getchar();
	}
	*p = 0;
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

int evaluate_RPN_expression(const char *expression) {
	char *p = expression;
	while (*p != '=') {
		if (isdigit(*p))
			push(*p - 48);
		else
			read_operator(*p);
		p++;
	}
	return pop();
}

