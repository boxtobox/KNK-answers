int evaluate_position(char board[8][8]) {
	int i, j;
	int value_white = 0;
	int value_black = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			switch (board[i][j]) {
			case 'Q': value_white += 9; break;
			case 'R': value_white += 5; break;
			case 'B': value_white += 3; break;
			case 'N': value_white += 3; break;
			case 'P': value_white += 1; break;
			case 'q': value_black += 9; break;
			case 'r': value_black += 5; break;
			case 'b': value_black += 3; break;
			case 'n': value_black += 3; break;
			case 'p': value_black += 1; break;
			}
		}
	}
	return value_white - value_black;
}
