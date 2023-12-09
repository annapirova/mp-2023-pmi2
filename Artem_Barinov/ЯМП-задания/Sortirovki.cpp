#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// починить рекурсию в слиянии
void output(int* arr, int len);
void prost(int* arr, int len) { // prostaya sortirovka
	int per;
	for(int i = 0; i<len-1;++i)
		for (int j = i+1; j < len; j++)
			if (arr[i] > arr[j]) {
				per = arr[i];
				arr[i] = arr[j];
				arr[j] = per;
			}
}
void puzir(int* arr, int len) { // sortirovka puzirkomx
	int per, flag; // flag i element dla perestanovki
	while (len>1) {
		flag = 0; // ne nado perestavlat
		for (int i = 1; i < len; i++)
			if (arr[i] < arr[i - 1]) {
				per = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = per;
				flag = i; // poslednii perestavlennii index esli bila perestonovka
			}
		len = flag; // do flaga v etom prohode otsortirovali
	}
}
void vstavka(int* arr, int len) {
	int newEl, loc;
	for (int i = 1; i < len; i++) {
		newEl = arr[i];
		loc = i - 1;
		while (loc>=0 && arr[loc]>newEl) {
			arr[loc + 1] = arr[loc];
			loc = loc - 1;
		}
		arr[loc + 1] = newEl;
	}
}
void slianie(int Lmass[], int Llen, int Rmass[], int Rlen, int Srtd[]) {
	int minIndL = 0;
	int minIndR = 0;
	
	int cnt = 0;
	while (minIndR < Rlen && minIndL < Llen) { // сливаем два подмассива пока один из них не закончится
		if (Lmass[minIndL] <= Rmass[minIndR]) {
			Srtd[cnt] = Lmass[minIndL++];
		}
		else {
			Srtd[cnt] = Rmass[minIndR++];
		}
		cnt++; // смещаем индекс в итоговом массиве
	}
	while (minIndR < Rlen) Srtd[cnt++] = Rmass[minIndR++];		
	while (minIndL < Llen) Srtd[cnt++] = Lmass[minIndL++];
}
void SlSort(int arr[], int len) {
	if (len > 1) {
		int mid = len / 2;
		int* Lmass = (int*)malloc(mid * sizeof(int));
		int* Rmass = (int*)malloc((len - mid) * sizeof(int));

		for (int i = 0; i < mid; i++)
			Lmass[i] = arr[i];
		for (int i = mid; i < len; i++)
			Rmass[i-mid] = arr[i];

		SlSort(Lmass, mid);
		SlSort(Rmass, len - mid);

		slianie(Lmass, mid, Rmass, len-mid, arr);
	}
}
void rascheska(int* arr, int len) {
	int per, flag;
	int s = len; // natalnii shag
	while (len>1) {
		s /= 1.247f;
		if (s < 1) s = 1;
		flag = 0;

		for (int i = 0; i+s < len; i++)
			if (arr[i] > arr[i + s]) {
				per = arr[i];
				arr[i] = arr[i + s];
				arr[i + s] = per;
				flag = i;

			}
		if (s == 1) len = flag + 1;
	}
}
void quickSort(int* arr, int left, int right) {
	if (left > right) return;
	int mid = arr[(left + right) / 2];
	int per;
	int i = left;
	int j = right;
	while (i<=j) {
		while (arr[i] < mid) i++;
		while (arr[j] > mid) j--;
		if (i <= j) {
			per = arr[i];
			arr[i++] = arr[j];
			arr[j--] = per;
		}
	}
	quickSort(arr, left, j);
	quickSort(arr, i, right);
}

void output(int* arr, int len) {
	for (int h = 0; h < len; h++)
		printf("%d ", arr[h]);
	printf("\n");
}
void copyMass(int* arrCopy, int* arr, int len) {
	memcpy(arrCopy, arr, sizeof(int) * len);
}
int main() {
	//int arr[10] = { 10, 89, 7, 67, 6, 56, 81, 1, 4, 34 };
	int arr[4] = { 89, 10,  67, 7};
	int len = *(&arr + 1) - arr;
	int arrCopy[10];

	//copyMass(arrCopy,arr, len);
	//printf("Prostaya sortirovka: "); prost(arrCopy, len); output(arrCopy, len); printf("\n");
	//copyMass(arrCopy, arr, len);
	//printf("Sortirovka puzirkom: "); puzir(arrCopy, len); output(arrCopy, len); printf("\n");
	//copyMass(arrCopy, arr, len);
	//printf("Sortirovka rascheskoi: "); rascheska(arrCopy, len); output(arrCopy, len); printf("\n");
	//copyMass(arrCopy, arr, len);
	//printf("Bistraya sortirovka: "); quickSort(arrCopy, 0, len-1); output(arrCopy, len); printf("\n");
	//copyMass(arrCopy, arr, len);
	//printf("Sortirovka vstavkoi: "); vstavka(arrCopy, len); output(arrCopy, len); printf("\n");
	copyMass(arrCopy, arr, len);

	printf("Sortirovka slianiem: "); SlSort(arrCopy, len); output(arrCopy, len); printf("\n");

	return 0;
}