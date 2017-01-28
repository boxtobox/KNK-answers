int evaluate_position(char board[8][8]) {
	char *p;
	int value_white = 0;
	int value_black = 0;
	for (p = &board[0][0]; p <= &board[7][7]; p++) {
		switch (*p) {
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
	return value_white - value_black;
}
