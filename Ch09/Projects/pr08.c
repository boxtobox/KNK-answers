#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
	int wins = 0, loses = 0;
	char play_again;
	srand((unsigned)time(NULL));
	do {
		if (play_game() == true) {
			printf("You win!\n");
			wins++;
		}
		else	{
			loses++;
			printf("You lose!\n");
		}
		printf("\nPlay again? ");
		scanf(" %c", &play_again);
	// play_again의 값이 '\n'이 되는걸 방지하기 위해 %c 앞에 빈 칸을 하나 둬서 whitespace 문자를 무시하게 한다.
		printf("\n");
	} while (toupper(play_again) == 'Y');

	printf("Wins: %d\tLosses: %d\n", wins, loses);
	return 0;
}

int roll_dice(void) {
	int dice1, dice2;
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}
bool play_game(void) {
	int sum, point;
	sum = roll_dice();
	printf("You rolled: %d\n", sum);
	if (sum == 7 || sum == 11)
		return true;
	else if (sum == 2 || sum == 3 || sum == 12)
		return false;
	else	{
		point = sum;
		printf("Your point is %d\n", point);
	}
	while (1) {
		sum = roll_dice();
		printf("You rolled: %d\n", sum);
		if (sum == point)
			return true;
		else if (sum == 7)
			return false;
	}
}
