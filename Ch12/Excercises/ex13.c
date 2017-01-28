int main(void) {
	double ident[N][N];
	double *p = &ident[0][0];
	int i = 0;
	while (i <= N * N - 1) {
		if (i % (N + 1) == 0)
			*(p + i) = 1.0;
		else
			*(p + i) = 0.0;
		i++;
	}
}
