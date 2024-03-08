#include<stdio.h>
int main ()
{
    int i,j;
    printf("enter the value of i and j to be swaped");
    scanf("%d%d",&i,&j);
    printf("vlaue of i =%d j=%d\n",i,j);
    int temp;
    temp=i;
    i=j;
    j=temp;
    printf("vlaue of i=%d,j=%d after the swap",i,j);

}
