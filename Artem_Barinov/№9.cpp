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
void Bin_toDec(char *sbin[100]) {
	int dec = 0;
	int len = strlen(sbin);

	for (int i = 0; i < len; i++) {
		if (sbin[i] == '1')
			dec += pow(2, len - i - 1);
	}
	printf("Decimal version: %d\n", dec);
}
int main() {
	char a;	
	int n;
	char s[100];
	printf("Enter 0 for dec to bin, or 1 for bin to dec: "); scanf_s("%c", &a, 1);
	printf("enter a number: ");
	if (a == '0') {
		scanf_s("%d", &n);
		Dec_to_Bin(n);
		return 0;
	}		
	if (a == '1') {
		scanf_s("%s", &s, 100);
		Bin_toDec(&s);
		return 0;
	}
	else
		printf("Wrong simbol\n");
	return 0;
}