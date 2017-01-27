#include <stdio.h>
int main()
{
	int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, first_sum, second_sum, total, checkd;
	printf("Enter the first 12 digits of a EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

	first_sum = i2 + i4 + i6 + i8 + i10 + i12;
	second_sum = i1 + i3 + i5 + i7 + i9 + i11;

	total = first_sum * 3 + second_sum;
	checkd = (10 - total % 10) % 10;

	printf("Check digit: %d\n", checkd);
}
