//номер 18(массивы)
#include"stdio.h"
#include"math.h"

int main()
{
	char mini = 10000;
	int n = 5;
	int a[5];
	int i;
	printf("Vvedite massiv:");
	for (i = 0; i<n ;i++)
	{
		scanf_s("%i", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}

	printf("\n");
	for (i = 1;i < (n - 1);i++)    //проверка всех, кроме первого и последнего
	{
		if ((a[i] < a[i + 1]) && (a[i] < a[i - 1]))
		{
			if (mini > a[i])
			{
				mini = a[i];
			}
		}
	}

	if (a[0] < a[1])    // проверка первого
	{
		if (mini > a[0])
		{
			mini = a[0];
		}
	}
	
	if (a[n - 1] < a[n - 2])  // проверка последнего
	{
		if (mini > a[n - 1])
		{
			mini = a[n - 1];
		}
	}
	
	printf("%i", mini);
}
