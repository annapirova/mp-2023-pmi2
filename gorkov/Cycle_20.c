//задача 20 из циклов
#include "stdio.h"
int main()
{
	long a, c, max, l, k, min, n;
	scanf("%ld", &a);
	max = -1;
	k = 1;
	min = 10;
	while (a != 0)
	{
		c = a % 10;
		if (c > max)
		{
			max = c;
			l = k;
		}
		if (c < min)
		{
			min = c;
			n = k;
		}
		a /= 10;
		k++;
	}
	//если слева, то k-l и k-n в printf
	printf("%ld =numberMax placeFromRight=%ld,\n%ld =numberMin place=%ld \n", max, l, min, n);
	return 0;

}