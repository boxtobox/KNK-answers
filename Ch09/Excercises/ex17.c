long long fact2(int n) {
	int i = 0;
	long long result = 1;
	for (i = 1; i <= n; i++)
		result *= i;
	return result;
}
