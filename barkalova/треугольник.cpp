#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	printf("Enter a height of Pascal triangle \n");
	scanf_s("%i", &n);
	for (int i = 1; i <= n; i++)
	{
		int Cnk = 1;
		/* ... */
		for (int k = 1; k <= i; k++)
		{
			printf("%i", Cnk);
			Cnk = Cnk * (i - k) / k;
		}
		printf("\n");
	}
}
