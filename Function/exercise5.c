//Functions with no arguments and no return values
#include<stdio.h>
void area();
int main()
{
    area();
    return 0;

}
area()
{
    int a,b;
    printf("Enter the length and with :");
    scanf("%d %d",&a,&b);
    int area=a*b;
    printf("Area is : %d",area);

}
