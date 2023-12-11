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
	printf("8. Merge Sort\n");
	printf("9. Test array\n");
	printf("10. Print sorted array\n");
	printf("11. Exit\n");
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
	}
	printf("select new command:\n");
}

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
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

void BubbleSort(int n, int B[], int A[], void AtoB(int n, int A[], int B[]))
{
	int i, j;
	int left = 0;
	int right = n - 1;
	int swap;

	AtoB(n, A, B);

	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);

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
	
	printf("\ntime: %f", time);
	printf("\n");
	printf("select new command:\n");
}

void insertionSort(int n, int B[], int A[], void AtoB(int n, int A[], int B[]))
{
	int i, key, j;

	AtoB(n, A, B);

	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);

	for (i = 1; i < n; i++)
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

	printf("time: %f", time);
	printf("\n");
	printf("select new command:\n");
}

void selectionSort(int B[], int n, int A[], void AtoB(int n, int A[], int B[]))
{
	int i, j, min, temp;

	AtoB(n, A, B);

	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceCounter(&start);

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
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

void Test(int B[], int n)
{
	int check = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (B[i] > B[i + 1])
		{
			printf("Array sorted with errors!\n");
			check = 1;
			break;
		}
	}

	if (check == 0)
	{
		printf("\nArray sorted without errors");
		printf("\n");
	}
	printf("select new command:\n");
}

void PrntS(int n, int B[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%i ", B[i]);
	}
	printf("\nselect new command:\n");
}

void AtoB(int n, int A[], int B[])
{
	for (int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
}

void Merge(int B[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* Left = (int*)malloc(n1 * sizeof(int));
	int* Right = (int*)malloc(n2 * sizeof(int));


	for (int i = 0; i < n1; i++)
	{
		Left[i] = B[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		Right[j] = B[mid + 1 + j];
	}

	int i = 0; 
	int j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (Left[i] < Right[j])
		{
			B[k] = Left[i];
			i++;
		}
		else
		{
			B[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		B[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		B[k] = Right[j];
		j++;
		k++;
	}

	free(Left);
	free(Right);
}

void Mergesort(int B[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;

		Mergesort(B, left, middle);
		Mergesort(B, middle + 1, right);

		Merge(B, left, middle, right);
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
			Print(A, n);
			break;
		}

		case 3:
		{
			Generate(A, &n, B);
			break;
		}

		case 4:
		{
			BubbleSort(n, B, A, AtoB);
			break;
		}

		case 5:
		{
			insertionSort(n, B, A, AtoB);
			break;
		}

		case 6:
		{
			selectionSort(B, n, A, AtoB);
			break;
		}

		case 7:
		{
			AtoB(n, A, B);

			LARGE_INTEGER freq, start, finish;
			double time;

			QueryPerformanceCounter(&start);

			quickSort(B, 0, n-1);

			QueryPerformanceCounter(&finish);

			QueryPerformanceFrequency(&freq);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

			printf("time: %f", time);
			printf("\n");
			printf("select new command:\n");
			break;
		}

		case 8:
		{
			AtoB(n, A, B);

			LARGE_INTEGER freq, start, finish;
			double time;

			QueryPerformanceCounter(&start);
			
			Mergesort(B, 0, n - 1);

			QueryPerformanceCounter(&finish);

			QueryPerformanceFrequency(&freq);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;

			printf("time: %f", time);
			printf("\n");
			printf("select new command:\n");
			break;
		}

		case 9:
		{
			Test(B, n);
			break;
		}

		case 10:
		{
			PrntS(n, B);
			break;
		}

		default:
			printf("type another number\n");
			break;
		}
	} while (k != 11);
}