#include <stdio.h>
#include <math.h> 
int main() {
	int N, i, a, p;
	int H[100];
	printf("Vvedite dlinnu massiva\n");
	scanf_s("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &H[i]);
	}
	for (a = 1; a <= N; a++)
	{
		p = 0;
		for (i = 0; i < N; i++)
		{
			if (H[i] == a)
			{
				p++;
			}
		}

		if (p != 1)
		{
			printf("massiv neyavl perestanovkoi\n");
			return 1;
		}
	}

	printf("massiv yavl perestanovkoi\n");
	return 0;
}