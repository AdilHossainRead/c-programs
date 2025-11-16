/*5. Function that takes two numbers as input and determines if the first number is greater than,
equal to or less than the second number.
Sample input Sample output
5 4 5 is greater than 4
2 6 2 is less than 6
8 8 8 is equal to 8
*/
#include<stdio.h>
void determine(int number1,int number2);
int main()
{
    int a,b;
    printf("Enter two number:");
    scanf("%d %d",&a,&b);
    determine(a,b);

}
void determine(int number1,int number2)
{
    if(number1>number2)
    {
      printf("%d is greater than %d",number1,number2);
    }else if(number1<number2)
    {
        printf("%d is less than %d",number1,number2);
    }else if(number1==number2)
    {
        printf("%d is equal %d",number1,number2);
    }
}
