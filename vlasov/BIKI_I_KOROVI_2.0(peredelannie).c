#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned int num1(int a) { // Cozdaem hislo 'a'
	srand(time(NULL));

	int* N;
	unsigned int G = 0;
	N = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++) {
		N[i] = rand() % 9 + 1;
		G += N[i] * (int)pow(10, i);
	}
	printf("Nomer: %u\n", G);
	return G;
}
void game(unsigned int G, int a) {
	printf("Poexali!\nNugno ygadat' hislo.\n");
	int arr[5];
	int N[5];
	int GC = G;
	for (int j = 0; j < a; j++) { N[j] = GC % 10; GC /= 10; }

	int bull = 0;
	int Popitka = 0; // kol-vo popitok
	do { 
		if (bull == a) { // *Vse ygadano - igra zaverhaetcya*
			printf("You win!!!\n");
			printf("Kol-vo popitok: %d\n", Popitka);
			return;
		}
		printf("vvedite chislo: ");
		unsigned int dig = 0;
		scanf_s("%u", &dig);

		if (dig == 0)
			return;
		int digC = dig;
		for (int j = 0; j < a; j++) {
			arr[j] = digC % 10;
			digC /= 10;
		}

		for (int i = 0; i < a; i++) { // proverka sovpadenii
			if (arr[i] == N[i]) {
				printf("Bull! tsifra hisla ygadana: %d;\n", N[i]);
				bull++;
				continue;
			}
			for (int k = 0; k < a; k++)
				{
				if (arr[k] == N[i]) {
					printf("Cows! tsifra hisla ygadana: %d;\n", N[i]);
					break;
				}
				else
					printf("Net sovpadenii!");
			}
		}
		++Popitka;
	} while (bull!=a);
}
int main() {
	int a;
	printf("Poexali!\n");
	do {
		printf("Vvedite chislo dlinnoi ot 2 do 5: \n");
		if (scanf_s("%d", &a) != 1) {
			printf("Nevernie cifri!\n");
			rewind(stdin);
			continue;
		}
		if (a > 1 && a < 6)
			break;
		else
			printf("Dlinna ne podxodit!\n");
	} while (1);

	game(num1(a), a);
	return 0;
}
