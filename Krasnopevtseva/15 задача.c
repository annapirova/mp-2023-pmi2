#include "stdio.h"
#include "stdio.h"
#include "locale.h"
#include "math.h"

int main() {
	setlocale(LC_CTYPE, "Russian");
	int n, m;
	printf("Введите n и m (2 <= n <= 10, 1 <= m <= 5): ");
	scanf("%d %d", &n, &m);
	if ((n < 2) ||  (n > 10) ||  (m < 1) || (m > 5)) {
		printf("Данные не соответствуют условиям задачи\n");
		return 1;
	}
	int maxch = 0;
	for (int i = 0; i < m; i++) {
		maxch += ((n - 1) * pow(n, i));
	}
	int  minch = 1 * pow(n, m - 1);

	for (int i = minch; i <= maxch; i++) {
		int k = i, j = m;
		int zxc[m];
		while (k != 0)
		{
			j--;
			zxc[j] = k % n;
			k /= n;
		}
		for (int z = j; z < m; z++)
		{
			printf("%d", zxc[z]);
		}
		printf("\n");

	}
	return 0;
}