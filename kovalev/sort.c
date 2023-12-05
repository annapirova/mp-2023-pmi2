#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
#include "string.h"
#include <time.h>
#include <sys/time.h>
double PortableGetTime()
{
    struct timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec * 1000000ULL + t.tv_usec) * 1.0e-6;
}
void menu()
{
  printf("perfect menu:\n1-write massiv\n2-generation massiv\n3-buble sort\n4-quick sort\n5-shell sort\n6-heap sort\n7-print not sorted massiv\n8-print sorted massiv\n9-back sort\n10-exit the program\n");
}
void proverka(int a[],int size)
{
  int i,flag=0;
  for(i=0;i<size-1;i++)
  {
    if(a[i]>a[i+1]) flag=1;
  }
  if(flag==0) printf("sort is succesful\n");
  else printf("sort isn't succesful\n");
}
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

int main()
{
srand(time(NULL));
menu();
int k=0, new_array=0, *a, *dubler, size=0, i,sort=0;
printf("What are you want?\n");
do
{
  scanf("%d",&k);
  switch (k)
  {
  case 1:
  {
    if(new_array==1)
    { free(a);
      free(dubler);
    }
    printf("Input size of massiv\n");
    scanf("%d", &size);
    a=(int *)malloc(sizeof(int)*size);
    dubler=(int *)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    {
      printf("Input a[%d]=",i);
      scanf("%d",&a[i]);
    }
    memcpy(dubler,a,sizeof(int)*size);
    new_array=1;
    sort=0;
    printf("sellect new command\n");
    break;
  }
    case 2:
    {
    if(new_array==1)
    { free(a);
      free(dubler);
    }
    printf("Input size of massiv\n");
    scanf("%d", &size);
    a=(int *)malloc(sizeof(int)*size);
    dubler=(int *)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    {
      a[i]=-1000+rand()%2001;
    }
    memcpy(dubler,a,sizeof(int)*size);
    new_array=1;
    sort=0;
    printf("sellect new command\n");
    break;
    }
    case 3:
    {
      if(new_array==1)
      {
      double start = PortableGetTime();
      Buble_sort(dubler,size);
      double finish = PortableGetTime();
      printf("time=%lf\n",finish - start);
      proverka(dubler,size);
      }
      else printf("pls input array");
      printf("sellect new command\n");
    }
    break;
    case 4:
    {
    if(new_array==1)
    {
      double start = PortableGetTime();
      quickSort(dubler,0,size-1);
      double finish = PortableGetTime();
      printf("time=%lf\n",finish - start);
      proverka(dubler,size);
    }
    else printf("pls input array");
    printf("sellect new command\n");
    break;
    }
    case 5:
    if(new_array==1)
    {
      double start = PortableGetTime();
      shellSort(dubler,size);
      double finish = PortableGetTime();
      printf("time=%lf\n",finish - start);
      proverka(dubler,size);
    }
    else printf("pls input array");
    printf("sellect new command\n");
    break;
    case 6:
    if(new_array==1)
    {
     double start = PortableGetTime();
     heapSort(dubler,size);
     double finish = PortableGetTime();
     printf("time=%lf\n",finish - start);
     proverka(dubler,size);
    }
    else printf("pls input array");
    printf("sellect new command\n");
    break;
    case 7:
    {
    for(i=0;i<size;i++)
    {
      printf("%d ",a[i]);
    }
    printf("\n");
    printf("sellect new command\n");
    break;
    }
    case 8:
    {
      if(sort==1)
      {
    for(i=0;i<size;i++)
    {
      printf("%d ",dubler[i]);
    }
    printf("\n");}
    else printf("please sort massiv\n");
    printf("sellect new command\n");
    break;
    }
    case 9:
    memcpy(dubler,a,sizeof(int)*size);
    printf("sellect new command\n");
    break;
    case 10:
    printf("Thanks for your attention!");
    break;

  default:
    printf("This command isn't exist. Please choose a new command\n");
    break;
  }
} while (k!=10);
free(a);
free(dubler);
return 0;
}
