//#include <stdio.h>
//#include <math.h>
//void perestanovka(int* arr, int len) {
//	
//	for (int i = 0; i < len - 1; i++) {
//		int flag = 0;
//		for (int j = i + 1; j < len; j++) {
//			if (arr[j] == arr[i]) {
//				printf("It isn`t perestanovka!\n");
//				return;
//			}
//			if (fabs(arr[i] - arr[j]) == 1)
//				flag = 1;
//		}
//		if (!flag) {
//			printf("It isn`t perestanovka!\n");
//			return;
//		}
//	}
//	printf("Perestanovka!\n");
//}
//int main() {
//	int arr1[11] = { 1,2,3,4,5,6,7,8,9, 10, 11 }; int len1 = *(&arr1 + 1) - arr1; // otsortirovano i perestanovka +
//	int arr2[10] = { 1,2,3,4,5,6,7,9, 10, 11 }; int len2 = *(&arr2 + 1) - arr2; // otsortirovano i neperestanovka (ne vse elementi ot 1 do N)
//	int arr3[9] = {1,9,2,8,3,7,4,6,5}; int len3 = *(&arr3 + 1) - arr3;			// neotsortirovano i perestonovka +
//	int arr4[10] = { 1,9,2,8,3,7,4,6,5, 12}; int len4 = *(&arr4 + 1) - arr4; // neotsortirovano i neperestonovka (ne vse elementi ot 1 do N)
//	perestanovka(arr1, len1);
//	perestanovka(arr2, len2);
//	perestanovka(arr3, len3);
//	perestanovka(arr4, len4);
//	return 0;
//}