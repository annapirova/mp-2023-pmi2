#include <stdio.h>
#include <math.h>


double minimum(double* arr, int len) {
	double min = 1000.0;
	for (int i = 0; i < len; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}
double maximum(double* arr, int len) {
	double max = 0.0;
	for (int i = 0; i < len; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
void exer29(int* arr, int len1) { // radiusi okruznostei so vsemi tochkami i bez nih: radius s okrugleniem do desatih
	int len = 10;
	double vecArr[10] = { 0 };
	for (int i = 0; i < len; i++)
		vecArr[i] = sqrt(pow(arr[i], 2) + pow(arr[i + 1], 2));
		
	double minRad = minimum(vecArr, len);
	double maxRad = maximum(vecArr, len);
	printf("Maximum radius: %.1lf\n", maxRad+0.1);
	printf("Minimum radius: %.1lf\n", minRad - 0.1);
}
int main() {
	int arr[20] = { 
		69.3 , 57.8,
		19.0 , 24.3,
		62.9 , 81.6,
		52.0 , 6.3,
		66.6 , 109.8,
		118.5 , 59.8,
		12.4 , 2.1,
		48.6 , 5.7,
		42.5 , 17.7,
		22.5 , 119.9 };
	int len = *(&arr + 1) - arr;
	exer29(arr, len);
	return 0;
}