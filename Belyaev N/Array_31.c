#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int Find_average(int a[], int n)
{
	int average, sum;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	average = sum / n;
	return average;
}


void func_one(int a[], int n) // a = salary
{	
	int average, count;
	count = 0;
	average = Find_average(a, n);
	for (int j = 0; j < n; j++)
	{
		if (a[j] > average)
		{
			count++;
		}
	}
	printf("%d - Employees have above average salaries\n", count);
}

void func_two(int a[], int n) // a = salary
{
	double min, average;
	double percent;
	min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	average = Find_average(a, n);
	percent = (average/min) * 100;
	printf("Need to increase by %.1f percent\n", percent);
}


void func_three(int a[], int b[], int n) // a = salary, b = workers
{
	int tmp, tmp_pos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				tmp_pos = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp_pos;
			}
		}
	}
	int min1, min2, min3, max1, max2, max3;
	int min1_pos, min2_pos, min3_pos, max1_pos, max2_pos, max3_pos;
	min1 = a[0]; min2 = a[1]; min3 = a[2]; max1 = a[n - 1]; max2 = a[n - 2]; max3 = a[n - 3];
	min1_pos = b[0], min2_pos = b[1], min3_pos = b[2]; max1_pos = b[n - 1], max2_pos = b[n - 2], max3_pos = b[n - 3];
	printf("Three employees with the highest salary:\n 1. Worker %d, His salary = %d\n 2. Worker %d, His salary = %d\n 3. Worker %d, His salary = %d\n Three employees with the lowest salary:\n 1.Worker %d, His salary = %d\n 2.Worker %d, His salary = %d\n 3.Worker %d, His salary = %d\n", max1_pos, max1, max2_pos, max2, max3_pos, max3, min1_pos, min1, min2_pos, min2, min3_pos, min3);
 }

void func_error()
{
	printf("Operation not found\n");
}



int main()
{
	int length, Operation;
	int* Workers;
	int* Salary;
	printf("Enter the number of employees: ");
	scanf_s("%d", &length);
	Workers = (int*)malloc(length * sizeof(int));
	Salary = (int*)malloc(length * sizeof(int));
	printf("Enter: Worker serial number, his salary\n");
	for (int i = 0; i < length; i++)
	{
		printf("Worker %d = ", i+1);
		scanf_s("%d", &Workers[i]);
		printf("His salary = ");
		scanf_s("%d", &Salary[i]);
	}
	printf("List of operations.\n 1 - Count the number of workers receiving wages above the average wage. \n 2 - Determine by what percentage the salary of the lowest paid employee needs to be increased so that he receives the average salary.\n 3 - Determine three serial numbers of employees receiving the highest salary and three serial numbers of employees receiving the lowest salary.\n 4 - Exit\n");
	Operation = 0;
	do 
	{
		printf("Enter operation: ");
		scanf_s("%d", &Operation);
		switch (Operation)
		{
		case 1: func_one(Salary, length); break;
		case 2: func_two(Salary, length); break;
		case 3: func_three(Salary, Workers, length); break;
		default: func_error(); break;
		}
	} while (Operation != 4);
	return 0;
}
