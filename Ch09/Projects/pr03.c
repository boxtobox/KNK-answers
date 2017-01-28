#include <stdio.h>
#include <stdbool.h>
#include <time.h>	// time function
#include <stdlib.h>	// srand, rand function
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);
void generate_random_walk(char walk[10][10]) {
	int i, j, k;
	int step = 1;
	int move, open_direction;
	bool possible_move[4];
	// array initialization
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			walk[i][j] = '.';
	}
	i = j = 0;
	walk[i][j] = 'A';

	srand((unsigned)time(NULL));
	while (step < 26) {
		bool possible_move[4] = { 1,1,1,1 };	// up left down right
		if (i == 0 || walk[i - 1][j] != '.')
			possible_move[0] = 0;
		if (j == 0 || walk[i][j - 1] != '.')
			possible_move[1] = 0;
		if (i == 9 || walk[i + 1][j] != '.')
			possible_move[2] = 0;
		if (j == 9 || walk[i][j + 1] != '.')
			possible_move[3] = 0;
		open_direction = 0;	// 이동 가능한 방향의 갯수. 4방향 모두 이동 가능하면 4, 모든 방향이 막혔으면 0
		for (k = 0; k < 4; k++)
			open_direction += possible_move[k];
		if (open_direction == 0)	// 아무 방향으로도 움직일 수 없으면 랜덤워크 종료
			return;
		do { move = rand() % 4; } while (possible_move[move] == 0);	// 막히지 않은 방향이 나올 때까지 move를 1~4 사이의 값으로 랜덤으로 구한다.
		switch (move) {
		case 0:	i--;	break;
		case 1:	j--;	break;
		case 2:	i++;	break;
		case 3: j++;	break;
		}
		walk[i][j] = 'A' + step;
		step++;
	}
}
void print_array(char walk[10][10]) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%3c", walk[i][j]);
		printf("\n");
	}
}
int main(void) {
	char board[10][10];
	generate_random_walk(board);
	print_array(board);
}
