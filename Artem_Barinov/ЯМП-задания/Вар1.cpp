//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//int game(unsigned int N) {
//	printf("You should guess the number\n");
//	unsigned int a = 0;
//	while (a != N) {
//		printf("Enter a value: ");
//
//		if (scanf_s("%d", &a) != 1) {
//			printf("Wrong simbol!\n");
//			rewind(stdin);
//			continue;
//		}
//		if (a > N)
//			printf("It is more, than the number!\n");
//		if (a < N)
//			printf("it is less, then the number!\n");
//	}
//	printf("You win!\n");
//	return 0;
//}
//int main() {
//	srand(time(NULL));
//	unsigned int N = rand() % 1000;
//	game(N);
//	return 0;
//}