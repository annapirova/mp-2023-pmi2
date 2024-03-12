#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
#include "string.h"
#include <time.h>
#include <sys/time.h>
#include "SORT_sortirovki.h"
#include "SORT_OST.h"
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
      else printf("pls input array\n");
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
    else printf("pls input array\n");
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
    else printf("pls input array\n");
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
    else printf("pls input array\n");
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
    for(i=0;i<size;i++)
    {
      printf("%d ",dubler[i]);
    }
    printf("\n");

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
