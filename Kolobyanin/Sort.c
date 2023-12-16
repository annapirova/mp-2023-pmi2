#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>

void menu()
{
	printf("1 - Generate array\n");
	printf("2 - Print generate array\n");
	printf("3 - Quick sort\n");
	printf("4 - Selection sort\n");
	printf("5 - Bubble sort\n");
	printf("6 - Insertion sort\n");
	printf("7 - Shell sort\n");
	printf("Select command\n");
}

void generate(int a[], int b[], int* n)
{
	int i, k;
	printf("Write count of elements: ");
	scanf_s("%d", n);
	for (i = 0; i < *n;i++)
	{
		k = 1 + rand() % 100;
		a[i] = k;
	}
	printf("\nSelect new command\n");
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("\nselect new command: \n");
}

void printarray(int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%i ", b[i]);
	}
}

void swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void proverka(int a[], int n)
{
	int i;
	int f = 0;
	for (i = 0; i < n - 1; i++) 
	{
		if (a[i] > a[i + 1]) 
		{
			f = 1;
		}
	}
	if (f == 0)
		printf("\nSorted correct\n");
	else
		printf("\nSorted error\n");
}

void copy(int a[], int b[], int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		b[i] = a[i];
	}
}

void quicksort(int a[], int l, int r)
{
	int mid = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
		{
			if (a[i] > a[j])
			{
				swap(&a[i], &a[j]);
			}
			i++;
			if (j > 0)
				j--;
		}
	}
	if (l < j)
		quicksort(a, l, j);
	if (i < r)
		quicksort(a, i, r);
}

void selectionsort(int a[], int n)
{
	int i, j, min;
	for (i = 0;i < n - 1;i++)
	{
		min = i;
		for (j = i + 1;j < n;j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[min], &a[i]);
	}
}

void insertionsort(int a[], int n)
{
	int i, j, k;
	for (i = 1; i < n; i++) {
		k = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
	}
}

void bubblesort(int a[], int n)
{
	int l = 0;
	int r = n - 1;
	int f = 1;
	while ((l < r) && f > 0)
	{
		f = 0;
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				f = 1;
			}
		}
		r--;
		for (int i = r; i > l; i--)
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i], &a[i - 1]);
				f = 1;
			}
		}
		l++;
	}
}

void shellsort(int a[], int n) 
{
	int k, tmp;
	for (k = n / 2; k > 0; k /= 2) 
	{
		for (int i = k; i < n; i ++) 
		{
			tmp = a[i];
			int j;
			for (j = i; j >= k && a[j - k] > tmp; j -= k)
				a[j] = a[j - k];
			a[j] = tmp;
		}
	}
}

int main()
{
	LARGE_INTEGER freq, start, finish;
	float t;
	QueryPerformanceFrequency(&freq);
	srand(time(NULL));
	int a[100000];
	int b[100000];
	int k;
	int n = 0;
	menu();
	do
	{
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:
		{
			generate(a,b,&n);
			break;
		}
		case 2:
		{
			print(a, n);
			break;
		}
		case 3:
		{
			copy(a, b, n);
			QueryPerformanceCounter(&start);
			quicksort(b, 0, n - 1);
			QueryPerformanceCounter(&finish);
			printarray(b, n);
			proverka(b, n);
			printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			printf("\nselect new command: \n");
			break;
		}
		case 4:
		{
			copy(a, b, n);
			QueryPerformanceCounter(&start);
			selectionsort(b,n);
			QueryPerformanceCounter(&finish);
			printarray(b, n);
			proverka(b, n);
			printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			printf("\nselect new command: \n");
			break;
		}
		case 5:
		{
			copy(a, b, n);
			QueryPerformanceCounter(&start);
			bubblesort(b, n);
			QueryPerformanceCounter(&finish);
			printarray(b, n);
			proverka(b, n);
			printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			printf("\nselect new command: \n");
			break;
		}
		case 6:
		{
			copy(a, b, n);
			QueryPerformanceCounter(&start);
			insertionsort(b, n);
			QueryPerformanceCounter(&finish);
			printarray(b, n);
			proverka(b, n);
			printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			printf("\nselect new command: \n");
			break;
		}
		case 7:
		{
			copy(a, b, n);
			QueryPerformanceCounter(&start);
			shellsort(b, n);
			QueryPerformanceCounter(&finish);
			printarray(b, n);
			proverka(b, n);
			printf("Sorted time: %.10lf \n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			printf("\nselect new command: \n");
			break;
		}
		default:
			printf("Command error");
		}
	} while (k != 8);
}