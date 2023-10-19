#include "stdio.h"
#include <stdlib.h>

int main()
{
	double n;
	int k, a, b, c;
	printf("Enter number N - ");
	scanf_s("%lf", &n);
	a = 0; b = 0; c = 0;
	while (a <= n)
		{
		while (b <= n)
			{
			while (c <= n)
				{
				if ((a <= b) && (b <= c))
					{
					if (a * a + b * b + c * c == n)
						{
						printf("\na = %d b = %d c = %d", a, b, c);
						}
					}
				c++;
				}
			c = 0;
			b++;
			}
		b = 0;
		a++;
		}
	return 0;
}