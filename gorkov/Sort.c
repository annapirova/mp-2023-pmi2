#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "windows.h"
#include "stdbool.h"

#define MAX_NUMS 50

int i, choise;
int n = MAX_NUMS;
int A[MAX_NUMS], Cp[MAX_NUMS];

void QuickSortRec(int a[], int l, int r)
{
	int mid, val, i, j, tmp;
	mid = (l + r) / 2;
	val = a[mid];
	i = l;
	j = r;
	while (i <= j)
	{
		while (a[i] < val)i++;
		while (a[j] > val) j--;
		if (i <= j) {
			tmp = A[i];
			a[i] = A[j];
			a[j] = tmp;
			i++;
			j--;
		}

	}
	if (l < j) QuickSortRec(a, l, i);
	if (i < r) QuickSortRec(a, i, r);

}

int increment(long inc[], long size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}


void shellSort(int a[], long size) {
	long inc, i, j, seq[40];
	int s;

	s = increment(seq, size);
	while (s >= 0) {
		inc = seq[s--];

		for (i = inc; i < size; i++) {
			int temp = a[i];
			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
				a[j + inc] = a[j];
			a[j + inc] = temp;
		}
	}
}

/*void ShellSort(int n, int mass[])
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}
}*/

void QuickSortNotRec(int a[], int l, int r)
{
	int lstack[100], rstack[100];
	int stacklen = 1;
	lstack[0] = 0;
	rstack[0] = n-1;
	int mid, val, i, j, tmp;	
	
	do {
		l = lstack[stacklen -1];
		r = rstack[stacklen -1];
		stacklen--;
		
		mid = (l + r) / 2;
		val = a[mid];
		i = l;
		j = r;
		while (i <= j)
		{
			while (a[i] < val)i++;
			while (a[j] > val) j--;
			if (i <= j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}

		}

		if (l <= j) {
			lstack[stacklen] = l;
			rstack[stacklen] = j;
			stacklen++;
		}
		if (i <= r) {
			lstack[stacklen] = i;
			rstack[stacklen] = r;
			stacklen++;
		}
	} while (stacklen != 0);
	
}


void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++) 
	{
		int j = i;
		while ((j > 0) && (a[j - 1] > a[j])) {
			int tmp = a[j-1];
			a[j-1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}

void Scan()
{
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
}

/*void Scan(int A, int n) {
	int top = 0;
	while (true) {
		int x;
		scanf_s("%d", &x);
		if (x == 0 || top == n) break;
		A[top] = x;
		top++;
	}
}*/
void Menu()
{
	printf("1 - scan mass\n");
	printf("2 - rand mass\n");
	printf("3 - to REsort same mass\n");
	printf("4 - QuickSort Not Recurs\n");
	printf("5 - QuickSort Recurs\n");
	printf("6 - InsertSort:\n");
	printf("7 - ShallSort\n");
	printf("8 - print mass\n");
	printf("9 - check sort mass\n");
	printf("10 - end\n");

}

void Rand()
{
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 1000;
	}
}

void Print(int a[])
{
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Check(int a[]) 
{	
	int z=0;
	for (i = 0; i < n-1; i++) 
	{
		if (a[i] > a[i + 1]) z++;
	}
	if (z == 0) printf("sorted");
	else printf("UNsorted");
}


int main()
{
	LARGE_INTEGER freq, start, finish;
	double time;
	QueryPerformanceFrequency(&freq);

	printf("Enter 0 to menu:\n");
		
	bool run = true;
	while (run) {
		scanf_s("%d", &choise);
		switch (choise)
		{
		case 0:
			Menu();
			break;
		case 1:
			Scan();
			printf("\n");
			memcpy(Cp, A, sizeof(int) * MAX_NUMS);
			break;
		case 2:
			Rand();
			memcpy(Cp, A, sizeof(int) * MAX_NUMS);
			printf("\n");
			break;
		case 3:
			memcpy(A, Cp, sizeof(int) * MAX_NUMS);
			break;
		case 4:
			QueryPerformanceCounter(&start);

			QuickSortNotRec(A, 0, n - 1);

			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("\n&%lf", time);
			printf("\n");
			break;
			
		case 5:
			QueryPerformanceCounter(&start);

			QuickSortRec(A, 0, n - 1);

			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("\n%lf", time);
			printf("\n");
			break;
		case 6:
			QueryPerformanceCounter(&start);

			InsertSort(A, n);

			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("\n&%lf", time);
			printf("\n");
			break;
		case 7:
			QueryPerformanceCounter(&start);

			shellSort(A, n);

			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("\n&%lf", time);
			printf("\n");
			
			break;
		case 8:
			Print(A);
			printf("\n");
			break;
		case 9:
			Check(A);
			printf("\n");
			break;
		case 10:
			
			run = false;
			printf("\n");
			break;
		default:
			
			printf("wrong operation. Enter 0 to menu");
			break;
		}
	}
	return 0;
	
	//InsertSort(A, n);
	
	
	
	
	
}