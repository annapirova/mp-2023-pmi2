#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int C[10]; int m,n=0,pov, index=-1,crpov=0,kolpov=0, lenB = 0;
	int B[10];
	printf("Введите массив из 10 элементов с повторами\n");
	for (int i = 0; i < 9; i++)
	{
		scanf_s("%d\n", &m);
		C[i] = m;
	}
	for (int i = 0; i < 10; i++)
	{
		pov = 1;
			for (int y = i +1; y < 10; y++)
				if (C[i] == C[y])
					pov++;
				if (pov > 1)
				{
					kolpov++;
					crpov += pov;
				}
	}
	crpov /= (kolpov + 1);
	for (int i = 0; i < 10; i++)
	{
		pov = 1;
		for (int y = i + 1; y < 10; y++)
			if (C[i] == C[y])
				pov++;
		if ((crpov < pov) && (C[index] != C[i]))
		{
			index = i;
			B[n] = C[index];
			n++;
			lenB++;
		}
	}
	printf("Искомый массив - ");
	if (crpov > 1)
	{
		for (int x = 0; x < lenB; x++)
		{
			printf("%d", B[x]);
		}
	
	}
	else
		printf("Массив не содержит повторов");
	return 0;
}