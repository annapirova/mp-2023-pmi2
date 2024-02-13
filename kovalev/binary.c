#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
#include "string.h"
int main(int args, char* argv[])
{
    int size;
    char* casei;
    if(args==3)
    {
        size=atoi(argv[1]);
        casei=argv[2];
    }
    if(args==2)
    {
        size=atoi(argv[1]);
    }
    srand(time(NULL));
    FILE* f;
    f=fopen("binary_bin.bin","wb");
    //printf("Input size of massiv\n");
    //scanf("%d", &size);
    int* a=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
      a[i]=-1000+rand()%2001;
      printf("%d ",a[i]);
    }
    printf("\n");
    fwrite(a,sizeof(int),size,f);
    fclose(f);
    f=fopen("binary_bin.bin","rb");
    fread(a,sizeof(int),size,f);
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    free(a);
    fclose(f);
    printf("\n %s", casei);
    return 0;
}