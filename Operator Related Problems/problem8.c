/* 8. Program that will take two numbers as inputs and print the maximum value. (Using
conditional operator - ?)
Sample input (x, y) Sample output
20 100 Max: 100
50 -20 Max: 50
*/
#include<stdio.h>
int main()
{
    int X,Y;
    printf("Enter two number:");
    scanf("%d %d",&X,&Y);
    if(X>Y)
        {
        printf("max=%d",X);
    }
    else
        {
     printf("max=%d",Y);
     }
}
