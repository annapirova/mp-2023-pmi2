#include "stdio.h"
#include <stdlib.h>

int main()
{
	double n;
	int i, k, top_number, count_div, maxdiv;
	count_div = 0; maxdiv = 0; k = 1; top_number = 0;
	printf("Enter number N - ");
	scanf_s("%lf", &n);
	while (k <= n)
		{
		for (i = 1; i <= k; i++)
			{
				if (k % i == 0) 
					{
						count_div++;
					}
			}
		if (maxdiv < count_div)
			{
				maxdiv = max(count_div, maxdiv);
				top_number = k;
			}
		count_div = 0;
		k++;
		}
	printf("Number with maximum divisors - %d\n", top_number);
	printf("Count divisors - %d", maxdiv);
	return 0;
}