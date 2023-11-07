#include "stdio.h"
#include <stdlib.h>

int main()
{
	double n;
	int k, attempts;
	n = 0;
	attempts = 0;
	srand(time(NULL));
	k = rand()%1000;
	printf("Hello! This is a simple game. You need to guess a number from 1 to 1000.\n");
	while (n != k)
		{
		printf("Enter your number - ");
		scanf_s("%lf", &n);
			if (n < k)
				{
					printf("More\n");
				}
			if (n > k)
				{
					printf("Less\n");
				}
		attempts++;
		}
	printf("You Win! Congratulations!\n");
	printf("Got it right in %d attempts", attempts);
	return 0;
}