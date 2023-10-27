//#include <stdio.h>
//
//int Cnter(double a, double b, double c) {
//	unsigned long long int cnt = 0;
//	long int x = -1000;
//	long int y = -1000;
//
//	for (; x <= 1000; x++) {
//		for (; y <= 1000; y++) {
//			if ((y >= (x * x + 2 * b * x + c)) && (y <= (2 * b + c)))
//				cnt++;
//		}
//		y = -1000;
//	}
//	return cnt;
//}
//double InpProt(char ch) {
//	double n;
//	printf("Enter %c: ", ch);
//	while (scanf_s("%lf", &n) != 1)
//	{
//		rewind(stdin);
//		printf("Error: invalid characters!\nEnter %c: ", ch);
//	}
//	return n;
//}
//int main() {
//	double a, b, c;
//	char s[100];
//	printf("Please, enter a numbers (a, b, c): \n");
//	a = InpProt('a');
//	b = InpProt('b');
//	c = InpProt('c');
//
//	printf("%d", Cnter(a, b, c));
//	return 0;
//}