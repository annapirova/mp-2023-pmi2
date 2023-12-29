#include <math.h>
#include <stdio.h>
int main()
{
	int N, a, b, c;
	printf("vvedite N\n");
	scanf_s("%d", &N);
	for (a = 0; a < 33; a++)
	{
		for (b = 0; b < 33; b++)
		{
			for (c = 0; c < 33; c++)
			{
				if (a* a + b * b + c * c==N)
				{
					printf("%d", a);
					printf("    ");
					printf("%d", b);
					printf("    ");
					printf("%d", c);
					printf("    \n");
					
				}

			}
		}
	}






}