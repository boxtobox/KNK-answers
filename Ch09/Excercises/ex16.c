long long fact1(int n) {
	return n == 1 ? 1 : n * fact1(n - 1);
}
