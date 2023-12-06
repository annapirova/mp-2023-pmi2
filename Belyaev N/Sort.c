#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"
#include "windows.h"


void create_array(int choise, int *length, int a[]) // Создание/повторное создание массива
{
	srand(time(NULL));
	int n = 0;
	printf("Select how to define the array (1 - Manual input; 2 - Random generation of a given length)\n");
	scanf_s("%d", &choise);
	printf("Enter length of array - ");
	scanf_s("%d", &n);
	if (choise == 1)
	{
		for (int i = 0; i < n; i++)
		{
			printf("A[%d] = ", i);
			scanf_s("%d", &a[i]);
		}
	}
	if (choise == 2)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 1000 + 1;
		}
	}
	*length = n;
	return a;
}

void show_array(int a[], int length) // Показ изначального массива
{
	for (int i = 0; i < length; i++)
	{
		printf("A[%d] = %d\n", i, a[i]);
	}
}

void duplicate(int* a, int length, int* b) // Создание дубликата массива А
{
	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
	}
	return b;
}

void hoarasort(int* b, int first, int last) // Сортировка Хоара
{
	int i = first, j = last;
	double tmp, x = b[(first + last) / 2];

	do {
		while (b[i] < x)
			i++;
		while (b[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoarasort(b, i, last);
	if (first < j)
		hoarasort(b, first, j);
}

void bubblesort(int* b, int length) // Сортировка пузырьком, двунаправленная.
{
	int left = 0;
	int right = length - 1;
	int flag = 1;
	int tmp;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (b[i] > b[i + 1])
			{
				tmp = b[i];
				b[i] = b[i + 1];
				b[i + 1] = tmp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (b[i - 1] > b[i])
			{
				tmp = b[i];
				b[i] = b[i - 1];
				b[i - 1] = tmp;
				flag = 1;
			}
	}
	left++;
	}	
}

void shellsort(int* b, int length) // Сортировка Шелла
{
	int i, j, step;
	int tmp;
	for (step = length / 2; step > 0; step /= 2)
		for (i = step; i < length; i++)
		{
			tmp = b[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < b[j - step])
					b[j] = b[j - step];
				else
					break;
			}
			b[j] = tmp;
		}
}

void mergesort(int* b, int length) // Сортировка слиянием
{
	int rght, rend;
	int i, j, m;
	int* c;
	c = (int*)malloc(length * sizeof(int));

	for (int k = 1; k < length; k *= 2)
	{
		for (int left = 0; left + k < length; left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > length) rend = length;
			m = left; i = left; j = rght;
			while (i < rght && j < rend)
			{
				if (b[i] <= b[j])
				{
					c[m] = b[i]; i++;
				}
				else
				{
					c[m] = b[j]; j++;
				}
				m++;
			}
			while (i < rght)
			{
				c[m] = b[i];
				i++; m++;
			}
			while (j < rend)
			{
				c[m] = b[j];
				j++; m++;
			}
			for (m = left; m < rend; m++)
			{
				b[m] = c[m];
			}
		}
	}
}

void insertionsort(int* b, int length) // Сортировка вставками
{
	int newElement, location;

	for (int i = 1; i < length; i++)
	{
		newElement = b[i];
		location = i - 1;
		while (location >= 0 && b[location] > newElement)
		{
			b[location + 1] = b[location];
			location = location - 1;
		}
		b[location + 1] = newElement;
	}
}

void show_sorted(int* b, int length) // Проверка на правильность сортировки массива
{
	int check = 0;
	for (int i = 0; i < length; i++)
	{
		printf("B[%d] = %d\n", i, b[i]);
	}
	for (int j = 0; j < length - 1; j++)
	{
		if (b[j] <= b[j + 1])
		{
			check++;
		}
	}
	if (check == length - 1)
	{
		printf("The array was sorted correctly!\n");
	}
	else
	{
		printf("The array was sorted incorrectly!\n");
	}
}

void func_error() // Команда не найдена
{
	printf("Operation not found\n");
}

int main()
{	
	LARGE_INTEGER freq, start, finish;
	float time;
	int choise, length;
	int* a;
	int* b;
	a = (int*)malloc(0 * sizeof(int));
	b = (int*)malloc(0 * sizeof(int));
	QueryPerformanceFrequency(&freq);
	int operation = 0;
	printf("Operation list:\n 1. Create/Recreate array.\n 2. Show array.\n 3. Quick Sort Hoara.\n 4. Bubble sort.\n 5. Shell sort.\n 6. Merge sort.\n 7. Insertion sort.\n 8. Check sorted array.\n 9. Exit\n");
	do {
		printf("Enter number of operation: ");
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 1: create_array(&choise, &length, a); break;
		case 2: show_array(a, length); break;
		case 3: duplicate(a, length, b);
			QueryPerformanceCounter(&start); hoarasort(b, 0, length - 1); QueryPerformanceCounter(&finish); printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart); break;
		case 4: duplicate(a, length, b); 
			QueryPerformanceCounter(&start); bubblesort(b, length); QueryPerformanceCounter(&finish); printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart); break;
		case 5: duplicate(a, length, b); 
			QueryPerformanceCounter(&start); shellsort(b, length); QueryPerformanceCounter(&finish); printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart); break;
		case 6: duplicate(a, length, b); 
			QueryPerformanceCounter(&start); mergesort(b, length); QueryPerformanceCounter(&finish); printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart); break;
		case 7: duplicate(a, length, b);
			QueryPerformanceCounter(&start); insertionsort(b, length); QueryPerformanceCounter(&finish); printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart); break;
		case 8: show_sorted(b, length); break;
		default: func_error(); break;
		}
	} while (operation != 9);
	return 0;
}
