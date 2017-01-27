#include <stdio.h>
int main()
{
	int i1, i2, i3, i4, temp;
	int smallest, largest;
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

	if (i1 > i2)  // 1개
	{
		temp = i2;
		i2 = i1;
		i1 = temp;
	}
	if (i3 > i4)  // 2개
	{
		temp = i4;
		i4 = i3;
		i3 = temp;
	}

	smallest = (i1 < i3) ? i1 : i3;  // 3개
	largest = (i2 > i4) ? i2 : i4;  // 4개
	printf("Largest : %d\n", largest);
	printf("Smallest: %d\n", smallest);
}
