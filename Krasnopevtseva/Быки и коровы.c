#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Russian");
	int i = 0, n, x, d = 0, s, bldk, korov, m;
	do
	{
		printf("Введи длину числа от 2 до 5\n");
		scanf("%d", &n);
	} while ((n < 2) || (n > 5));

	int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (i; i < n; i++)
	{
		x = rand() % 9;
		while (array[x] == -1)
		{
			x = rand() % 9;
		}
		d += (array[x] * pow(10, i));
		array[i] = -1;
	}
	printf("Попробуй угадать)\n");
	scanf("%d", &s);
	while (s != d)
	{
		int d1 = d;
		int dz[n];
		int sz[n];
		bldk = 0;
		korov = 0;
		i = n - 1;
		while (i >= 0)
		{
			for (m = 0; m < n; m++)
			{
				int y = pow(10, i);
				dz[m] = d1 / y;
				sz[m] = s / y;
				d1 %= y;
				s %= y;
				i--;
			}
		}
		for (m = 0; m < n; m++)
		{
			if (dz[m] == sz[m])
				korov++;
			else
			{
				for (i = 0; i < n; i++)
				{
					if (dz[m] == sz[i])
						bldk++;
				}
			}
		}
		printf("Не угадал, коров - ""%d" ", быков -" "%d\n", korov, bldk);
		printf("Давай по-новой\n");
		scanf("%d", &s);
	}
	if (s == d)
	{
		printf("да ты хорош\n");
	}

	return 0;
}