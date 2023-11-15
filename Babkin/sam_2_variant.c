#include "stdio.h"
#include "stdbool.h"
int main()
{
	int a[7] = { 3,12,34,56,89,100,101 };
	int b[7] = { 9,23,12,67,69,90,100 };
	int c[7] = {0,0,0,0,0,0,0};
	int p, g;
	for (p = 0; p < 7; p++)
	{
		bool flac = true;
		for (g = 0; g < 7; g++)
		{
			if (a[p] == b[g])
			{
				flac = false;
				break;
			}
		}
		if (flac == true)
		{
			c[p] = a[p];
		}
		if (c[p] != 0)
		{
			printf("%d\n", c[p]);
		}
	}
}