#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* num1(int a) { // генерация числа длины А
	srand(time(NULL));

	int* N;
	N = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++)
		N[i] = rand() % 10 + 1;
	return N;
}
void game(int* N, int a) {// игра
	printf("The game started!\nYou have to guess the number.\n");
	int arr[5];
	

	do { //сама игра
		printf("Enter a number: ");
		unsigned int dig = 0;
		scanf_s("%u", &dig);
		/*if (scanf_s("%u", &dig) != 1) {
			printf("Wrong simbol! Try again!\n");
			rewind(stdin);
			continue;
		}*/
		if (dig == 0)
			return;
		int digC = 0;
		for (int j = 0; j < a; j++) {
			arr[j] = dig % 10;
			digC /= 10;
		}

		for (int i = a; i >= 0; i--) {
			for (int k = 0; k < a; k++) {
				if (arr[k] == N[i])
					printf("Cow! You guessed a digital of number: %d;\n", N[i]);
			}
			int f = i;
			for (int k = 0; k < a; k++) {
				if (arr[k] == N[f]) {
					printf("Bull! You guessed a digital of number: %d;\n", N[i]);
					f--;
				}
			}
		}
	} while (1);
}
int main() {
	int a;
	printf("Game 'Bulls and cows' begins!\n");
	do {
		printf("Enter a length of number with length from 2 to five: \n");
		if (scanf_s("%d", &a) != 1) {
			printf("Wrong simbols! Try again!\n");
			rewind(stdin);
			continue;
		}
		if (a > 1 && a < 6)
			break;
		else
			printf("Wrong length! Try again!\n");
	} while (1);

	game(num1(a), a);
	return 0;
}