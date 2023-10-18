#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int size = 10;
	int array[10], kol=0;
	printf("Ââåäèòå ìàññèâ èç 10 ýëåìåíòîâ\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	for (int i = 0; i < size; i++)
		for (int m = 0; m < size; m++)
			if (array[m] == array[i] && m != i)
				kol++;
	if (kol == 0)
		printf("Îäèíàêîâûõ ýëåìåíòîâ íåò \n");
	else
	{
		printf("Ïîâòîðåíèÿ åñòü â êîëè÷åñòâå " "%d " "øòóê", kol);
	}
	return 0;
}
