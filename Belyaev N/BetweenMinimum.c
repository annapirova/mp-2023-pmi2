#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int main()
{
	int* array;
	int length, min1, min2, min1_pos, count, min2_pos, i;
	printf("Enter length of array - ");
	scanf_s("%d", &length);
	array = (int*)malloc(length * sizeof(int));
	for (int current = 0; current < length; current++)
	{
		printf("Enter the %d element of the array: ", current);
		scanf_s("%d", &array[current]);
	}
	min1 = array[0];
	min1_pos = min2_pos = 0;
	for (i = 0; i < length; i++)
	{
		if (array[i] < min1)
		{
			min1 = array[i];
			min1_pos = i;
		}
		if (array[i] == min1)
		{
			min2 = min1;
			min2_pos = i;
		}
	}
	if (min1_pos == min2_pos)
	{
		printf("Second minimum element not found");
	}
	if (min1_pos != min2_pos)
	{
		count = min2_pos - min1_pos - 1;
		printf("Count of elements between minimum values: %d", count);
	}

	return 0;
}