#include <stdio.h>
#include <math.h>
#include <string.h>

void Dec_to_Bin(int n) {
	int BinInd[100];
	int i = 0;
	while (n>0)	{
		BinInd[i] = n % 2;
		n = n / 2;
		i++;
	}
	printf("The binary version: ");
	for (int j = i-1; j >= 0;j--)
		printf("%d", BinInd[j]);
}
void Bin_to_Dec(long int bin) {
	char s[1];
	int cnt = 0;
	double dec = 0;

	while (bin!=0) {
		int g = bin % 10;
		bin = bin / 10;
		if (g == 1)
			dec += pow(2, cnt);
		cnt++;
	}
	printf("Decimal version: %.1lf\n", dec);
}
int main() {
	char a;	
	int n;
	printf("Enter 0 for dec to bin, or 1 for bin to dec: "); scanf_s("%c", &a, 1);
	printf("enter a number: "); scanf_s("%d", &n);
	if (a == '0')	
		Dec_to_Bin(n);	
	if (a == '1')
		Bin_to_Dec(n);
	else
		printf("Wrong simbol\n");
	return 0;
}