
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"

#define MAX_NUMS 5
int main()
{
	srand(time(0));
	int a[MAX_NUMS];
	int i = 0;
	int n = MAX_NUMS;
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}

	int k = 0;
	for (i = 1; i < (n - 1); i++)
	{
		while (a[i] < a[i + 1])
		{
			i++;
		}
		if ((a[i] >= a[i + 1]) && a[i - 1] < a[i]) k++;

	}
	for (i = 1; i < (n - 1); i++)
	{
		while (a[i] > a[i + 1])
		{
			i++;
		}
		if ((a[i] <= a[i + 1]) && a[i - 1] > a[i]) k++;

	}
	printf(" \nintervals of monotony= %d \n", k);

	return 0;

}