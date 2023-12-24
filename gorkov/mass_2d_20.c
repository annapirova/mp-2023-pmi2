#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define g 22

int main()
{
	srand(time(0));

	int i, j, n;
	printf("Enter count of people\n");
	scanf_s("%d", &n);
	printf("Money   Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct \n");
	printf("   hours/money h/m  h/m   h/m   h/m   h/m   h/m   h/m   h/m   h/m \n");
	int** Mass;
	Mass = (int**)malloc((n+1) * sizeof(int*));
	for (i = 0; i < n+1; i++) {
		Mass[i] = (int*)malloc((g+1) * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		Mass[i][0] = ((rand() % 10)+1)*100;
		

	}
	int sum=0;
	for (i = 0; i < n; i++) {
		for (j = 1; j < g; j = j + 2)
		{
			Mass[i][j] = rand() % 10;
		}
		for (j = 2; j < g+1; j=j + 2) {
			Mass[i][j] = Mass[i][0] * Mass[i][j-1];
			
		}
		
	}
	for (j = 2; j < g+1; j += 2) {
		sum = 0;
		for (i = 0; i < n; i++) {
			sum += Mass[i][j];
		}
		Mass[n][j] = sum;
	}
	
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < g + 1; j++)
		{

			printf("%d ", Mass[i][j]);
		}
		printf("\n");
	}
	printf("\nsum=");
	for (j = 2; j < g + 1; j += 2)printf("  %d ", Mass[n][j]);

	for (int i = 0; i < n + 1; i++) free(Mass[i]);
	free(Mass);
	return 0;
}