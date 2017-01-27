#include <stdio.h>
int main()
{
	int grade;
	char letter_grade;
	printf("Enter numerical grade: ");
	scanf("%d", &grade);
	if (grade < 0 || grade > 100)
	{
		printf("Invalid input.\n");
		return 0;
	}
	switch (grade / 10)
	{
	case 10: case 9:	letter_grade = 'A';		break;
	case 8:				letter_grade = 'B';		break;
	case 7:				letter_grade = 'C';		break;
	case 6:				letter_grade = 'D';		break;
	default:		    letter_grade = 'F';		break;
	}
	printf("Letter grade: %c\n", letter_grade);
	return 0;

}
