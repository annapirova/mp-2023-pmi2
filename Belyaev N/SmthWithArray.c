#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int main()
{
	int* array;
	int x, _min, a, b, length;
	printf("Enter length of array - ");
	scanf_s("%d", &length);
	array = (int*)malloc(length * sizeof(int));
	for (int current = 0; current < length; current++)
	{
		printf("Enter the %d element of the array: ", current);
		scanf_s("%d", &array[current]);
	}
	printf("Enter some number = ");
	scanf_s("%d", &x);
	_min = 1e9;
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (abs(x - array[i] - array[j]) < _min)
			{
				_min = abs(x - array[i] - array[j]);
				a = array[i];
				b = array[j];
			}
		}
	}
	printf("a = %d\n", a);
	printf("b = %d", b);
	return 0;
}