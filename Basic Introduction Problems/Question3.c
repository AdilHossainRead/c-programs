#include<stdio.h>
int main()
{
    int a,b;
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
    int sum=a+b;
    int multi=a*b;
    int rem=a%b;
    printf("sum = %d\n",sum);
    printf("sum = %d\n",multi);
    printf("sum = %d\n",rem);
}
