//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//int game(unsigned int N) {
//	printf("You should guess the number\n");
//	while (1) {
//		unsigned int a = 0;
//		printf("Enter a value: ");
//
//		if (scanf_s("%d", &a) != 1) {
//			printf("Wrong simbol!\n");
//			rewind(stdin);
//			continue;
//		}
//		else
//			if (a == N) {
//				printf("You win!\n");
//				return 0;
//			}
//		if (a > N)
//			printf("It is more, than the number!\n");
//		if (a < N)
//			printf("it is less, then the number!\n");
//	}
//	return 0;
//}
//int main() {
//	srand(time(NULL));
//	unsigned int N = rand() % 1000;
//	game(N);
//	return 0;
//}