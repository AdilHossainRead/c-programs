#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter first number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    printf("Enter third number:");
    scanf("%d",&c);
    printf("Enter fourth number:");
    scanf("%d",&d);
    int sum=a+b+c+d;
    float ave=sum/4;
    printf("Average = %.2f",ave);
}
