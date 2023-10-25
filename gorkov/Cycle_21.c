//задача 21 из циклов
#include "stdio.h"
int main()
{
	int a, c, k, l;
	scanf_s("%d", &a);
	k = 10;
	l = 0;
	while (a != 0)
	{
		c = a % 10;
		if (c > k)
		{
			printf("no, another");
			l = 1;
			break;
		}
		a /= 10;
		k = c;
	}
	if (l != 1) printf("da, neybyv");
	return 0;
}