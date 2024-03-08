#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("enter the value of the array numbers: ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }free(a);

}
