double inner_product(const double *a, const double *b, int n) {
	double *p = a, *q = b, sum = 0.0;
	int i;
	for (i = 0; i < n; i++)
		sum += *(p + i)**(q + i);
	return sum;
}
