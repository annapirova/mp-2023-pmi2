#ifndef SORT_sortirovki__
#define SORT_sortirovki__
void Buble_sort(int a[], int size);
void quickSort(int a[], int left, int right);
int increment(int inc[], int size);
void shellSort(int a[], int size);
void downHeap(int a[],int k, int n);
void heapSort(int a[], int size);
#endif