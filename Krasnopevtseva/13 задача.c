#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double b, c, f1, f2;
	int kol=0, x=-100, y=-100;
	printf("Введите вещественное b\n");
	scanf_s("%lf", &b);
	printf("Введите вещественное c\n");
	scanf_s("%lf", &c);
	f2 = 2 * b + c;
	for (x; x <=100; x++)
	{
		for (y; y <= 100; y++)
		{
			f1 = x * x + 2 * b * x + c;
			if ((y >= f1) && (y <= f2))
			{
				kol++;
			}
		}
		y = -100;
	}
	printf("Количество целых точек %d\n", kol);
	return 0;
	




	
}