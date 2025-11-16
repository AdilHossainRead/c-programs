//Functions with arguments and return values
#include<stdio.h>
int area(int a,int b);
int main()
{
    int length,width;
    printf("Enter length and width:");
    scanf("%d%d",&length,&width);
    int res=area(length,width);
    printf("Area is:%d ",res);
}
int area(int a,int b)
{
    int y=a*b;
    return y;
}
