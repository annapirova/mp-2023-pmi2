#include <stdio.h>
int main(){
	int c;
	int k = 10, k1, k2, result = 1;
	scanf_s("%d", &c);
	while ((c > 0)&&(result==1)) {
		k1 = c % k;
		c /= 10;
		k2 = c % k;
		result = (k1 >= k2);
		
	}
	printf("%d",result);
	return 0;
}