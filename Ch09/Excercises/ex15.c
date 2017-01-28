double median(double x, double y, double z) {
	double result;
	if (x <= y) {
		if (y <= z) result = y;
		else if (x <= z) result = z;
		else result = x;
	}
	if (z <= y) result = y;
	if (x <= z) result = x;
	result = z;
	return result;
}
