#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

void Menu()
{
	printf("hi, user, what do u want to do?\n");
	printf("1. Write array\n");
	printf("2. Print unsorted array\n");
	printf("3. Generate array\n");
	printf("4. Bubble Sort\n");
	printf("5. Insertion Sort\n");
	printf("6. Selection Sort\n");
	printf("7. Quick Sort\n");
	printf("8. Exit\n");
}

void Write(int A[], int *n, int B[])
{
	int p, element;
	printf("write count of elements: ");
	scanf_s("%i", n);
	for (p = 0; p < *n; p++)
	{
		scanf_s("%i", &element);
		A[p] = element;
		B[p] = element;
	}
	printf("select new command:\n");
}

void Print(int A[], int *n)
{
	for (int i = 0; i < *n; i++)
	{
		printf("%i ", A[i]);
	}
	printf("\n");
	printf("select new command:\n");
}

void Generate(int A[], int* n, int B[])
{
	int p, element;
	printf("write count of elements: ");
	scanf_s("%i", n);
	for (p = 0; p < *n; p++)
	{
		element = 1 + rand() % 100;
		A[p] = element;
	}
	printf("select new command:\n");
}

void BubbleSort(int *n, int B[], int A[])
{
	int i, j;
	int left = 0;
	int right = *n - 1;
	int swap;

	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);

	for (int i = 0; i < *n; i++)
	{
		B[i] = A[i];
	}

	while (left < right)
	{
		swap = 0;
		for (i = left; i < right; i++)
		{
			if (B[i] > B[i + 1])
			{
				int temp = B[i];
				B[i] = B[i + 1];
				B[i + 1] = temp;
				swap = 1;
			}
		}
		right--;

		if (!swap)
		{
			break;
		}

		swap = 0;
		for (j = right; j > left; j--)
		{
			if (B[j] < B[j - 1]) 
			{
				int temp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = temp;
				swap = 1;
			}
		}
		left++;

		if (!swap)
		{
			break;
		}
	}
	QueryPerformanceCounter(&finish);

	QueryPerformanceFrequency(&freq);
	time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

	int check = 0;
	for (int i = 0; i < *n-1; i++)
	{
		if (B[i] > B[i + 1])
		{
			printf("Array sorted with errors!");
			check = 1;
			break;
		}
	}
	
	for (int i = 0; i < *n; i++)
	{
		printf("%i ", B[i]);
	}

	if (check == 0)
	{
		printf("\nArray sorted without errors");
		printf("\n");
	}
	
	printf("time: %f", time);
	printf("\n");
	printf("select new command:\n");
}

void insertionSort(int *n, int B[], int A[])
{
	int i, key, j;

	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);
	for (int i = 0; i < *n; i++)
	{
		B[i] = A[i];
	}

	for (i = 1; i < *n; i++)
	{
		key = B[i];
		j = i - 1;

		while (j >= 0 && B[j] > key)
		{
			B[j + 1] = B[j];
			j = j - 1;
		}
		B[j + 1] = key;
	}
	QueryPerformanceCounter(&finish);

	QueryPerformanceFrequency(&freq);
	time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

	int check = 0;
	for (int i = 0; i < *n - 1; i++)
	{
		if (B[i] > B[i + 1])
		{
			printf("Array sorted with errors!");
			check = 1;
			break;
		}
	}

	for (int i = 0; i < *n; i++)
	{
		printf("%i ", B[i]);
	}

	if (check == 0)
	{
		printf("\nArray sorted without errors");
		printf("\n");
	}
	printf("time: %f", time);
	printf("\n");
	printf("select new command:\n");
}

void selectionSort(int B[], int *n, int A[])
{
	int i, j, min, temp;
	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);

	for (int i = 0; i < *n; i++)
	{
		B[i] = A[i];
	}

	for (i = 0; i < *n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < *n; j++)
		{
			if (B[j] < B[min])
			{
				min = j;
			}
		}

		temp = B[min];
		B[min] = B[i];
		B[i] = temp;
	}
	QueryPerformanceCounter(&finish);

	QueryPerformanceFrequency(&freq);
	time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

	int check = 0;
	for (int i = 0; i < *n - 1; i++)
	{
		if (B[i] > B[i + 1])
		{
			printf("Array sorted with errors!");
			check = 1;
			break;
		}
	}

	for (int i = 0; i < *n; i++)
	{
		printf("%i ", B[i]);
	}

	if (check == 0)
	{
		printf("\nArray sorted without errors");
		printf("\n");
	}
	printf("time: %f", time);
	printf("\n");
	printf("select new command:\n");
}

void quickSort(int B[], int left, int right)
{
	int i = left, j = right, mid = B[(left + right) / 2];

	do {
		while (B[i] < mid)
		{
			i++;
		}
		while (B[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			if (B[i] > B[j])
			{
				int temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
			i++;
			if (j > 0)
			{
				j--;
			}
		}
	} while (i <= j);

	if (i < right)
	{
		quickSort(B, i, right);
	}
	if (j > left)
	{
		quickSort(B, left, j);
	}
}



void main()
{
	srand(time(NULL));
	Menu();

	int k, n = 0;
	int A[100000];
	int B[100000];

	do
	{
		scanf_s("%i", &k);
		switch (k)
		{
		case 1:
		{
			Write(A, &n, B);
			break;
		}

		case 2:
		{
			Print(A, &n);
			break;
		}

		case 3:
		{
			Generate(A, &n, B);
			break;
		}

		case 4:
		{
			BubbleSort(&n, B, A);
			break;
		}

		case 5:
		{
			insertionSort(&n, B, A);
			break;
		}

		case 6:
		{
			selectionSort(B, &n, A);
			break;
		}

		case 7:
		{
			for (int i = 0; i < n; i++)
			{
				B[i] = A[i];
			}

			LARGE_INTEGER freq, start, finish;
			double time;

			QueryPerformanceCounter(&start);

			quickSort(B, 0, n-1);

			QueryPerformanceCounter(&finish);

			QueryPerformanceFrequency(&freq);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

			int check = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (B[i] > B[i + 1])
				{
					printf("Array sorted with errors!");
					check = 1;
					break;
				}
			}

			for (int i = 0; i < n; i++)
			{
				printf("%i ", B[i]);
			}

			if (check == 0)
			{
				printf("\nArray sorted without errors");
				printf("\n");
			}
			printf("time: %f", time);
			printf("\n");
			printf("select new command:\n");
			break;
		}

		default:
			printf("type another number\n");
			break;
		}
	} while (k != 8);
}