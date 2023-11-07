#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int size = 10;
	int array[10], razn=1000000, x, razn1, z, c;
	printf("Задайте массив из 10 жлементов\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("Задайте число\n");
	scanf_s("%d", &x);
	for (int i = 0; i < size; i++)
		for (int m = 0; m < size; m++)
		{
			razn1 = abs((array[m] + array[i]) - x);
			if (razn1 < razn)
			{
				razn = razn1;
				z = array[m];
				c = array[i];
			}
		}
	printf("Ближайщая сумма к числу - " "%d " "+ " "%d", z, c);
	
	return 0;
}