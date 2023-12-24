#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main() 
{	
	srand(time(0));

	int i,j,n,m;
	printf("Enter count of str\n");
	scanf_s("%d", &n);
	printf("Enter len of str\n");
	scanf_s("%d", &m);

	int** Mass;
	Mass = (int**)malloc((n+1) * sizeof(int*));
	for (i = 0; i < n+1; i++) {
		Mass[i] = (int*)malloc((m+1) * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		{
			Mass[i][j] = rand() % 100;
			if ((Mass[i][j]-(Mass[i][j] % 10)) > 9) printf("%d  ", Mass[i][j]);
			else printf("%d   ", Mass[i][j]);
		}
		printf("\n");
	}
	int choise;
	printf("Enter 1var/2var\n");
	scanf_s("%d", &choise);
	int s;
	int copy = 0;
	switch (choise)
	{
		
	case 1:
		
		printf("Enter number of str\n");
		scanf_s("%d", &s);
		for (j = 0; j < m; j++) {
			Mass[n][j] = 0;
		}
		int* tmp;
		tmp = Mass[s - 1];
		Mass[s - 1] = Mass[n];
		Mass[n] = tmp;

		for (i = (n); i > s; i--) {
			tmp = Mass[i - 1];
			Mass[i - 1] = Mass[i];
			Mass[i] = tmp;
		}


		for (i = 0; i < n + 1; i++) {
			for (j = 0; j < m; j++) printf("%d ", Mass[i][j]);
			printf("\n");
		}

		for (int i = 0; i < n + 1; i++) free(Mass[i]);
		free(Mass);
		break;
	case 2:
		printf("Enter number of column\n");
		scanf_s("%d", &s);	
		for (i = 0; i < n; i++)
		{
			for (j = m; j > s-1; j--) {
				Mass[i][j] = Mass[i][j-1];
		}
			Mass[i][s - 1] = 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m+1; j++) printf("%d ", Mass[i][j]);
			printf("\n");
		}
		for (int i = 0; i < n + 1; i++) free(Mass[i]);
		free(Mass);
		break;
	default:
		break;
	}

	return 0;
}