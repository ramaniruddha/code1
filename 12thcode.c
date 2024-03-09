#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a=(int *)malloc(sizeof(int));
    int i,n,j;
    printf("enter the no n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("\n%d\n",a[i]);
    }
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]<a[j+1]==0)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     for(i=0;i<n;i++)
    {
        printf("\n%d\n",a[i]);
    }

    return 0;
}
