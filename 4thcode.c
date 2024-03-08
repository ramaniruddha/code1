#include<stdio.h>
int main()
{
    int a,b,c,d;
    while(1)
    {


    printf("enter the value of numbers");
    scanf("%d%d",&a,&b);
    printf("enter the 1 for addiction ,2 for subtraction,3 for multiplication,4 for division ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: d=a+b;
        printf("%d",d);
        break;

        case  2: d=a-b;
        printf("%d",d);
        break;

        case 3: d=a*b;
        printf("%d",d);
        break;

        case 4:d=a%b;
        printf("%d",(float)d);
        break;

        default:printf("not valid oprator ");


    }
    }
}
