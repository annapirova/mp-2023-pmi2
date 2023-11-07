#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	double proc = 0.0;
	int r1 = 2 + rand() % 10, sum = 0, average = 0, workers1 = 0, min = 10000000;
	int numbers[100], n = 0;
	int salary[100];

	printf("Порядковые номера = ");
	for (int i = 0; i < r1; i++)
	{
		numbers[i] = rand() % 101;
		n++;
		printf("%i ", numbers[i]);
	}

	printf("\n");
	printf("Зарплаты = ");
	for (int i = 0; i < r1; i++)
	{
		salary[i] = 10000 + rand() % 90000;
		sum += salary[i];
		printf("%i ", salary[i]);
	}

	average = (sum / n);

	for (int i = 0; i < n; i++)
	{
		if (salary[i] > average)
		{
			workers1++;
		}
		
		if (salary[i] < min)
		{
			min = salary[i];
		}
	}

	if (min < average)
	{
		proc = average - min;
		proc = proc / min*100;
	}



	printf("\n");
	printf("Минимальная зарплата = %i\n", min);
	printf("Средняя зарплата по фирме = %i\n", average);
	printf("Процент = %lf", proc);


	return(0);
}