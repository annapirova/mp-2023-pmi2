#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "string.h"
#include "SORT_sortirovki.h"
void Buble_sort(int a[], int size) {
  int j, k = size-1;
  int left=0, right = size-1; 
  int tmp;
  do {
    int flag=0;
    for( j=right; j>=left; j-- ) {
      if ( a[j-1] > a[j] ) {
        tmp=a[j-1];
        a[j-1]=a[j];
        a[j]=tmp;
        k=j;
        flag=1;
      }
    }
    left = k+1;
    for (j=1; j<=right; j++) {
      if ( a[j-1] > a[j] ) {
        tmp=a[j-1];
        a[j-1]=a[j];
        a[j]=tmp;
        k=j;
        flag=1;
      }
    }
    right = k-1;
    if(!flag) break;
  } while ( left < right );
}
void quickSort(int a[], int left, int right)
{
	int i = left, j = right, mid = a[(left + right) / 2];

	do {
		while (a[i] < mid)
		{
			i++;
		}
		while (a[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
      }
			  i++;
			  j--;
    }
	} while (i <= j);

	if (i < right)
	{
		quickSort(a, i, right);
	}
	if (j > left)
	{
		quickSort(a, left, j);
	}
}
int increment(int inc[], int size) {
  int p1, p2, p3, s;
  p1 = p2 = p3 = 1;
  s = -1;
  do {
    if (++s % 2)
    {
      inc[s] = 8*p1 - 6*p2 + 1;
    } 
    else
    {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
	p1 *= 2;
  } while(3*inc[s] < size);  
  if(s>0) return --s;
  else return 0;
}
void shellSort(int a[], int size) {
  int inc, i, j, seq[40];
  int s;
  s = increment(seq, size);
  while (s >= 0) {
	inc = seq[s--];
  for (i = inc; i < size; i++) {
      int temp = a[i];
      for (j = i-inc; (j >= 0) && (a[j] > temp); j -= inc)
        a[j+inc] = a[j];
      a[j+inc] = temp;
    }
  }
}
void downHeap(int a[],int k, int n) {
  int new_elem;
  int child;
  new_elem = a[k];

  while(k <= n/2) {  		
    child = 2*k;
    if( child < n && a[child] < a[child+1] ) 
    child++;
    if( new_elem >= a[child] ) break; 
    a[k] = a[child];  
    k = child;
  }
  a[k] = new_elem;
}
void heapSort(int a[], int size) {
  int i;
  int temp;
  for(i=size/2-1; i >= 0; i--) downHeap(a, i, size-1);
  for(i=size-1; i > 0; i--) {
    temp=a[i]; a[i]=a[0]; a[0]=temp;
    downHeap(a, 0, i-1); 
  }
}