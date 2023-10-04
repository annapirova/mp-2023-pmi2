#include"stdio.h"
int main()
{
	int a, b, count = 0;
	printf("vvedite\n");
	scanf_s("%i", &a);
	while (a != 1000)
	{
		scanf_s("%i", &b);
		if (b == 1000)
		{
			break;
		}
		if (a > 0 && b < 0 || a < 0 && b>0)
		{
			count++;
		}
		a = b;
	}
	printf("chislo peremen = %i\n", count);
}