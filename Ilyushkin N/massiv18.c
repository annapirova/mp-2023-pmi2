#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void auto_massiv(int n, int G[])
{
	int c, i;
	printf("ykazhite max znachenie el-ta massiva__\n");
	scanf_s("%d", &c);
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		G[i] = rand() % (c + 1);
	}
}
void manual_massiv(int n, int G[])
{
	int  c, i;
	for (i = 0; i < n; i++)
	{
		printf("ykazhite %d element massiva__", i);
		scanf_s("%d", &c);
		G[i] = c;
	}
}
int main()
{
	int z, n, tym, G[100000];
	int kaz = 0;
	printf("massiv zadacha 18\n");
	printf("kakoi dlinni massiv zhelaete(max 1000000)\n");
	scanf_s("%d", &n);
	if (n > 100000)
	{
		return -1;
	}
	do
	{
		printf("press 1(ispolzovat auto massiv)\n ");
		printf("press 2(ispolzovat manual massiv)\n ");
		scanf_s("%d", &z);
		switch (z)
		{
		case 1:
			auto_massiv(n, G);
			kaz++;
			break;
		case 2:
			manual_massiv(n, G);
			kaz++;
			break;
		default:
			printf("takoe nelza vibrat'\n");
			printf("try one more time\n");
			break;
		}
	} while (kaz != 1);
	int i, a;
	int b = 100000;
	a = 100001;
	for (i = 0; i < n; i++)
	{
		if ((i == 0 && G[i] < G[i + 1])
			|| (i == n - 1 && G[i - 1] > G[i])
			|| (G[i - 1] > G[i] && G[i] < G[i + 1]))
		{
			a = G[i];
		}
		if (a < b)
		{
			b = a;
		}
	}
	printf("%d vash minimum\n",b);
}