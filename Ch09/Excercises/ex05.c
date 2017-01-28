int num_digits(int n) {
	int digits = 0;
	while (n > 0) {
		n /= 10;
		digits++;
	}
	return digits;
}
