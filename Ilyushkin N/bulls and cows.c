#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	int n = 0;
	int m, b;
	int G[5];
	int R[5];
	int h = 0;
	int v = h+1;
	int gf = 1;
	int chislo;
	int j=1 ;
	int f ;
	int o = 0;
	int bulls = 0;
	int cows = 0;
	int d = 0;
	int cx ;
	printf("vedite n\n");
	scanf_s("%d", &n);
	srand(time(NULL));
	switch (n)
	{
	case 2:
		G[2] = 10;
		G[3] = 11;
		G[4] = 12;
		R[2] = 13;
		R[3] = 14;
		R[4] = 15;
		break;

	case 3:
		G[3] = 10;
		G[4] = 11;
		R[3] = 13;
		R[4] = 14;
		break;
	case 4:
		G[4] = 10;
		R[4] = 10;
		break;
	case 5:
		break;
	default:
		printf("n ne vipolniaet yslovie\n");
		return -1;
		break;
	}

	int i = 0;
	do
	{
		gf = 1;
		for (i = 0; i < n; i++)
		{
			G[i] = rand() % 10;

		}

		h = 0;
		v = h + 1;
		while (h != n - 1)
		{
			for (v = h + 1; v < n; v++)
				if (G[h] == G[v])
				{
					gf = 0;
				}
				
				
			h++;
		}
		
	} while (gf == 0);




		for (int i = 0; i < n; i++) {
			printf("%d ", G[i]);
		}
	do
	{
		bulls = 0;
		cows = 0;
		j = 1;
		printf("\nvvedite vashe chislo\n");
			scanf_s("%d", &chislo);
			for (i = 1; i <= n-1; i++)
			{
				j = j * 10;
			}
			f = chislo / j;
			printf("%d\n", f);
			if (f < 1 || f > 9)
			{
				printf("vi vveli chislo ne podhodiashee ysloviIO^_^\n");

			}
			else
			{   
				for (o = 0; o < n; o++)
				{
					R[n - 1 - o] = chislo % 10;
					chislo = chislo / 10;
				}
				i = 0;
				for (int i = 0; i < n; i++) {
					printf("%d ", R[i]);
				}
				o = 0;
				while (o != n + 1)
				{
					for (cx = o; cx < n; cx++)
						if (R[o] == G[cx])
						{
							if (o == cx)
							{
								bulls++;
							}
							else
							{
								cows++;
								break;
							}
						}
					o++;
				}

				printf("bulls %d\n", bulls);
				printf("cows %d\n", cows);
			}
	} while (bulls != n);

	printf("Success! You are win!!\n");
	return 0;
}