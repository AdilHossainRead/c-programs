//Functions with arguments and no return values
#include<stdio.h>
void area(int length, int width);
int main()
{
    int a,b;
    printf("Enter length and width :");
    scanf("%d %d",&a,&b);
    area(a,b);
    return 0;
}
 void area(int length, int width)
{
    int area=length*width;
    printf("%d",area);
}
