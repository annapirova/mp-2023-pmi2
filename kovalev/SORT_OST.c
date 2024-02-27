#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
#include "string.h"
#include <time.h>
#include <sys/time.h>
#include "SORT_OST.h"
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