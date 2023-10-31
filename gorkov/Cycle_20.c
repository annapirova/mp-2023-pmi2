//cycle 20 
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
	//for b) replace k-l and k-n in printf
	printf("%ld =numberMax placeFromRight=%ld,\n%ld =numberMin place=%ld \n", max, l, min, n);
	return 0;

}
