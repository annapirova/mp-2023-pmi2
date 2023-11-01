#include <math.h>
#include <stdio.h>
main() {
	int N, i, c, h;
	int G[100];	
	printf("write how long the massiv\n");
	scanf_s("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &G[i]);
	}
	for (c = 1; c <= N; c++)
	{
		h = 0;
		for (i = 0; i < N; i++)
		{
			if (G[i] == c)
			{
				h++;
			}
		}

		if (h != 1)
		{
			printf("massiv ploh\n");
			return -1;
		}

	}

	printf("massiv horosh\n");
	return 0;
}