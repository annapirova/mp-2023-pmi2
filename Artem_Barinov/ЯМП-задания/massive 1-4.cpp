//#include <stdio.h>
//
//// файл 1-4 обязательные задачи
//void InPlace(double* arr, int len) { // first exercise
//	for (int i = 0; i < len - 1; i++)
//		for (int j = i + 1; j < len; j++)
//			if (arr[i] == arr[j])
//				arr[j] = -1.0;
//	double total[10] = { 0 };
//	int cnt = 0;
//	for (int k = 0; k < len; k++)
//		if (arr[k] != (-1.0)) {
//			total[k] = arr[k];
//			cnt++;
//		}
//	for (int i = 0; i < len; i++)
//		if (total[i] != 0)
//			printf("%lf\n", total[i]);
//	printf("Number of unique elements: %d\n", cnt);
//}
//
//void NoRepMas(int* arr1, int len1, // second exercise
//	int* arr2, int len2) {
//	int NRep[20]={ 0 };
//	int n = 0, i = 0, j = 0;
//
//	while ((i < len1) && (j < len2)) {
//		if (arr1[i] < arr2[j])
//			NRep[n++] = arr1[i++];
//		else if (arr1[i] > arr2[j])
//			NRep[n++] = arr2[j++];
//		else {
//			NRep[n++] = arr1[i++];
//			++j;
//		}
//	}
//	while (i < len1) NRep[n++] = arr1[i++];
//	while (j < len2) NRep[n++] = arr2[j++];
//
//	for (int k = 0; k < n; k++)
//		if (NRep[k] != -1)
//			printf("%d\n", NRep[k]);
//}
//void OnlyRepMas(int* arr1, int len1, // third and fourth exercises
//	int* arr2, int len2) {
//	int arr3[20]={ 0 };
//	int cnt = 0;
//	for (int i = 0; i < len1; i++)
//		for (int j = 0; j < len2; j++)
//			if (arr1[i] == arr2[j])
//				arr3[i] = arr1[i];
//
//	for (int i = 0; i < (*(&arr3 + 1) - arr3) - 1; i++) {
//		for (int j = i + 1; j < *(&arr3 + 1) - arr3; j++)
//			if (arr3[i] == arr3[j])
//				arr3[i] = -1;
//		if (arr3[i] != -1)
//			printf("%d\n", arr3[i]);
//	}
//}
//
//void NoRep(int* arr, int len) { // no repetitions function
//	for (int i = 0; i < len - 1; i++)
//		for (int j = i + 1; j < len; j++)
//			if (arr[i] == arr[j])
//				arr[j] = -1.0;
//}
//int main() {
//	printf("Exercise #1: \n");
//	double arr[10] = { 66.1, 119.7, 18.9, 23.8, 119.7, 87.7, 119.7, 91.6, 18.9, 95.4 };
//	int len = *(&arr + 1) - arr;
//	InPlace(arr, len);
//
//
//	int arr1[10] = { 119, 82, 119, 1, 18, 23, 7, 98, 18, 10 }; int len1 = *(&arr1 + 1) - arr1;
//	NoRep(arr1, len1);
//	int arr2[10] = { 117, 81, 119, 10, 108, 23, 65, 78, 6,  10 }; int len2 = *(&arr2 + 1) - arr2;
//	NoRep(arr2, len2);
//
//	printf("\nExercise #2: \n");
//	NoRepMas(arr1, len1, arr2, len2);
//
//	printf("\nExercise #3: \n");
//	OnlyRepMas(arr1, len1, arr2, len2);
//
//	printf("\nExercise #4: \n");
//	return 0;
//}