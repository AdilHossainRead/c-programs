/*10. Function to take two positive numbers x and y as input and calculate x to the power y.
Sample         input Sample output
3 4            3 to the power 4 is 81
10 3           10 to the power 3 is 1000*/
#include<stdio.h>
void power(int number1, int number2);
int main()
{
    int x,y;
    printf("Enter tow positive integer: ");
    scanf("%d %d",&x ,&y);
    power(x,y);
    return 0;
}
void power(int number1, int number2)
{
    int result=1;
    for(int i=1;i<=number2;i++)
    {
        result*=number1;

    }printf("%d to the power %d is %d",number1,number2,result);
}
