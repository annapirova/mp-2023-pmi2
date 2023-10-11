//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int* num1(int a) {
//	srand(time(NULL));
//
//	int* N;
//	N = (int*)malloc(a * sizeof(int));
//	for (int i = 0; i < a; i++)
//		N[i] = rand() % 10 + 1;
//	return N;
//}
//void game(int* N, int a) {
//	printf("The game started!\nYou have to guess the numbers.\n");
//	
//	do{
//		int dig;
//		scanf_s("%", dig);
//		for (int i = 0; i < a; i++)
//		{
//			if (dig == N[i])
//				printf("Cow! You guess a digital with number %d\n", i);
//			else
//				printf("No matches! Try again!\n");
//		}
//	} while (1);
//}
//int main() {
//	int a;
//	printf("Game 'Bulls and cows' begins!\n");
//	do {
//		printf("Enter a length of number with length from 2 to five: \n"); 
//		if (scanf_s("%d", &a) != 1) {
//			printf("Wrong simbols! Try again!\n");
//			rewind(stdin);
//			continue;
//		}
//		if (a > 1 && a < 6)
//			break;
//		else
//			printf("Wrong length! Try again!\n");
//	} while (1);
//	
//	game(num1(a), a);
//	return 0;
//}