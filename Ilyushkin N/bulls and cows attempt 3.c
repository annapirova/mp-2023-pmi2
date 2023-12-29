#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	int n, a, b, c, i, bulls, cows, me, ch,v, mi, h, G[4], R[4];
	n = 0;
	ch = 0;
	srand(time(NULL));
	printf("privet igraem v bulls and cows\n");
	printf("vvedi zhelaemoe n     ");
	scanf_s("%d", &n);
	if (n < 1 || n>5)
	{
		printf("tvoe n ne sootvestvyet ysloviIO\n");
		return 0;
	}

	do {
		c = 1;
		for (i = 0; i < n; i++)
		{
			G[i] = rand() % 10;
		}
		if (G[0] == 0)
		{
			c = 0;
		}
		for (i = 0; i < n - 1; i++)
		{
			for (a = i + 1; a < n; a++)
				if (G[i] == G[a])
				{
					c = 0;
				}
		}
	} while (c == 0);
	do
	{
		bulls = 0;
		cows = 0;
		mi = 0;
		do
		{
			ch = 0;
			printf("vashe chislo_");
			scanf_s("%d", &mi);
			me = mi;
			while (me != 0) {
				me = me / 10;
				ch++;
			}
			if (ch != n)
			{
				printf("vashe chislo ne podhodit\n");
				printf("vvedite eshe raz\n");
				printf("%d", ch);
			}
		} while (ch != n);
		for (i = n - 1; i >= 0; i--)
		{
			h = mi % 10;
			mi = mi / 10;
			R[i] = h;
		}
		for (i = 0; i < n; i++)
		{
			
			for (v = 0; v < n ; v++)
			{
				if (G[i] == R[v])
				{
					if (i == v)
					{
						bulls++;
					}
					else
					{
						cows++;
					}


				}
			}
		}
		printf("cows here -- %d\n", cows);
		printf("bulls here -- %d\n", bulls);
	} while (bulls != n);
	printf("YRA you are win!\n");
	printf(" your number is -- ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", G[i]);
	}
}


        
