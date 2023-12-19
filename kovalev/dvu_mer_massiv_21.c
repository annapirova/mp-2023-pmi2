#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main()
{
    printf("input count elementov\n");
    int n,m=5,i,delta;
    scanf("%d", &n);
    int **q=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        q[i]=(int*)malloc(m*sizeof(int));
    }
    printf("\n");
    int max[5]={-1};
    int min[5]={100};
    int sred[5]={0};
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++)
        {
        q[i][j]=1+rand()%5;
        if(q[i][j]>max[j]) max[j]=q[i][j];
        if(q[i][j]<min[j]) min[j]=q[i][j];
        sred[j]+=q[i][j];
        printf("%2d ", q[i][j]);
        }
       printf("\n");
    }
    for(i=0;i<5;i++)
    sred[i]=sred[i]/n;
    printf("input delta for sred znach\n");
    scanf("%d",&delta);
    int *unik=(int*)malloc((n+1)*sizeof(int));
    int *usred=(int*)malloc((n+1)*sizeof(int));
    int unik_bool=0, usred_bool=0;
    for(i=0;i<n+1;i++)
    {
        unik[i]=usred[i]=-1;
    }
    int zxc1=0,zxc2=0;
    for (int i = 0; i < n; i++) {
        int maxstr=0;
        int absstr=0;
        int minstr=0;
       for (int j = 0; j < m; j++)
       {if(q[i][j]==max[j]) maxstr++;
       if(q[i][j]==min[j]) minstr++;
       if(q[i][j]<sred[j]+delta && q[i][j]>sred[j]-delta ) absstr++;
       }
       if (maxstr>2 || minstr>2)
       {
        unik[zxc1]=i;
        zxc1++;
        unik_bool=1;
       }
       if (absstr==5)
       {
        usred[zxc2]=i;
        zxc2++;
        usred_bool=1;
       }
    }
    if(unik_bool==1)
    {
    printf("Unikalnie: ");
    for(i=0;unik[i]!=-1;i++)
    {
        printf("%d ",unik[i]);
    }
    }
    else printf("Unikal is not");
    printf("\n");
    if(usred_bool==1)
    {
    printf("Usredn: ");
    for(i=0;usred[i]!=-1;i++)
    {
        printf("%d ",usred[i]);
    }
    }
    else printf("usred is not");
    printf("\n");
    printf("\n");
    printf("\n");
    // look sred znach po stolbcam
    /*
    for(i=0;i<m;i++)
    printf("%d  ", sred[i]);
    */
    free(unik);
    free(usred);
    for(i=0;i<n;i++)
    {
        free(q[i]);
    }
    free(q);

    return 0;
}