#include <stdio.h>
#define NUM_STUDENTS 5
#define NUM_QUIZZES 5
int main(void)
{
	int a[NUM_STUDENTS][NUM_QUIZZES], low, high, total_quiz, i, j;
	int total[NUM_STUDENTS] = { 0 };
	total_quiz = 0;
	for (i = 0; i < NUM_STUDENTS; i++)
	{
		printf("Enter quiz grade of student %d: ", i + 1);
		for (j = 0; j < NUM_QUIZZES; j++)
			scanf("%d", &a[i][j]);
	}

	printf("Total grade of each student: ");
	for (i = 0; i < NUM_STUDENTS; i++) {
		for (j = 0; j < NUM_QUIZZES; j++)
			total[i] += a[i][j];
	}
	printf("\n");
	printf("\t\tTOTAL\tAVERAGE\n");
	for (i = 0; i < NUM_STUDENTS; i++)
	{
		printf("STUDENT %d\t%3d\t%5.2f\n", i+1, total[i], (float)total[i] / NUM_QUIZZES);
	}
	printf("\n");

	printf("\tAVERAGE\tHIGH\tLOW\n");
	for (j = 0; j < NUM_QUIZZES; j++) {
		printf("QUIZ %d", j+1);
		high = low = a[0][j];
		for (i = 0; i < NUM_STUDENTS; i++) {
			high < a[i][j] ? high = a[i][j] : 1;
			low > a[i][j] ? low = a[i][j] : 1;
			total_quiz += a[i][j];
		}
		printf("\t%5.2f\t%3d\t%3d\n", (float)total_quiz / NUM_STUDENTS, high, low);
		total_quiz = 0;
	}

	return 0;
}
