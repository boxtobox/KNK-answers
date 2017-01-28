int gcd2(int m, int n) {
	if (n == 0) return m;
	else gcd2(n, m%n);
}
