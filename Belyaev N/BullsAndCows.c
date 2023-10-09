#include "stdio.h"
#include <stdlib.h>
#include "math.h"

int check(int k, int length)
{
	if (length == 2)
	{
		int d1, d2;
		d1 = k % 10;
		k = k / 10;
		d2 = k % 10;
		if (d1 == d2)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
	}
	if (length == 3)
	{
		int d1, d2, d3;
		d1 = k % 10;
		k = k / 10;
		d2 = k % 10;
		k = k / 10;
		d3 = k % 10;
		if ((d1 == d2) || (d1 == d3) || (d2 == d3))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (length == 4)
	{
		int d1, d2, d3, d4;
		d1 = k % 10;
		k = k / 10;
		d2 = k % 10;
		k = k / 10;
		d3 = k % 10;
		k = k / 10;
		d4 = k % 10;
		if ((d1 == d2) || (d1 == d3) || (d1 == d4) || (d2 == d3) || (d2 == d4) || (d3 == d4))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (length == 5)
	{
		int d1, d2, d3, d4, d5;
		d1 = k % 10;
		k = k / 10;
		d2 = k % 10;
		k = k / 10;
		d3 = k % 10;
		k = k / 10;
		d4 = k % 10;
		k = k / 10;
		d5 = k % 10;
		if ((d1 == d2) || (d1 == d3) || (d1 == d4) || (d1 == d5) || (d2 == d3) || (d2 == d4) || (d2 == d5) || (d3 == d4) || (d3 == d5) || (d4 == d5))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}





int main()
{
	int length, n, n_number, n_tmp, k, k_number, k_tmp, i, j, bulls, cows, l, r;
	n = 0; bulls = 0; cows = 0;
	printf("Hello! This is a simple game. Write lenght of \n");
	srand(time(NULL));
	printf("Hello! This is a simple game. You need to guess the number guessed by the computer using hints.\nRules:\n Cow - some number from your number is in the hidden number.\n Bull - some number from your number is in its position in the hidden number");
	printf("\nEnter number length from 2 to 5 - ");
	scanf_s("%d", &length);
	l = pow(10, length - 1);
	r = pow(10, length);
	k = l + abs(rand()) % (r - l);
	while (check(k, length) != 1)
	{
		k = l + abs(rand()) % (r - l);
	}
	while (n != k)
	{
		printf("\nEnter your number - ");
		scanf_s("%d", &n);
		n_number = n;
		for (i = 1; i <= length; i++)
		{
			n_tmp = n_number % 10;
			n_number = n_number / 10;
			k_number = k;
			for (j = 1; j <= length; j++)
			{
				k_tmp = k_number % 10;
				k_number = k_number / 10;
				if ((n_tmp == k_tmp) && (j == i))
				{
					bulls++;
				}
				if ((n_tmp == k_tmp) && (j != i))
				{
					cows++;
				}
			}
		}
		printf("Cows: %d\nBulls: %d", cows, bulls);
		bulls = 0;
		cows = 0;
	}
	printf("\nYou guessed it right!");
	return 0;
}