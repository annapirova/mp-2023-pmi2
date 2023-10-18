#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int main() {
	int n;
	int Z[2], X[3], C[4], V[5];
	int G;
	printf("vedite n/n");
	scanf_s("%d", n);
	switch (n)
	{
	case 2:
	  G = Z;
	  break;
	case 3:
		G = X;
		break;
	case 4:
		G = C;
		break;
	case 5:
		G = V;
		break;
	default:
		printf("n ne do yslovie");
		return -1;
		




	}







}