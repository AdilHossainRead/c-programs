//Functions with no arguments and return values
#include<stdio.h>
int area();
int main()
{
    //int a,b;
    int result=area();
    printf("Area = %d",result);
}
int area(int length, int width)
{
    printf("Entet length and width:");
    scanf("%d %d",&length,&width);
    int res=length*width;
    return res;
}
