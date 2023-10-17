#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* num1(int a) { // генерация числа длины А
	srand(time(NULL));

	int* N;
	unsigned int H = 0;
	N = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++) {
		N[i] = rand() % 9 + 1;
		printf("%d", N[i]);
		H += N[i] * (int)pow(10, i);
	}
	return N;
}
void game(int* N, int a) {// игра
	printf("The game started!\nYou have to guess the number.\n");
	int* arr = (int*)malloc(a * sizeof(int));	

	do { //сама игра
		printf("Enter a number: ");
		unsigned int dig = 0;
		scanf_s("%u", &dig);
		
		if (dig == 0)
			return;
		int digC = dig;
		for (int j = 0; j < a; j++) {
			arr[j] = digC % 10;
			digC /= 10;
		}

		for (int i = 0; i < a; i++) {
			if (arr[i] == N[i])
				printf("Bull! You guessed a digital of number: %d;\n", N[i]);
			for (int k = 0; k < a; k++)
				if (arr[k] == N[i]) {
					printf("Cow! You guessed a digital of number: %d;\n", N[i]);
					break;
			}			
		}
	} while (1);
	free(arr);
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