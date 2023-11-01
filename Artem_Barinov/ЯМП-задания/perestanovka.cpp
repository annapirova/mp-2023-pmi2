//#include <stdio.h>
//
//void perestanovka(int* arr, int len) {
//	//int* arr[9] = {1,2,3,4,5,6,7,8,9};
//	for (int i = 0; i < len-1; i++)
//		for (int j = i+1; j < len; j++)
//			if(arr[j]==arr[i]) {
//				printf("It isn`t perestanovka!\n");
//				return;
//			}
//	printf("Perestanovka!\n");
//}
//int main() {
//	int arr1[11] = { 1,2,3,4,5,6,7,8,9, 10, 11 }; int len1 = *(&arr1 + 1) - arr1;
//	int arr2[11] = { 1,9,2,3,5,7,8,4,7,6,5 }; int len2 = *(&arr2 + 1) - arr2;
//	perestanovka(arr1, len1);
//	perestanovka(arr2, len2);
//	return 0;
//}