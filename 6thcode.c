#include<stdio.h>
int main()
{
    int a;
    int *p;
    p=&a;
    printf("%d \n",*p);
    printf("%d\n",p);
    a=9;
    printf("%d\n",*p);
    *p=10;
    printf("%d",a);
}
