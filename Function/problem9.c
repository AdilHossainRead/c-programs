/*9. Function to calculate the factorial of a number.
Sample input          Sample output
3                      6
5                      120
*/
#include<stdio.h>

int factorial(int number);
int main()
{
    int x;
    printf("Enter a integer number: ");
    scanf("%d",&x);
    int y=factorial(x);
    printf("Factorial is: %d",y);

}
int factorial(int number)
{
    int fact=1;
    for(int i=1;i<=number;i++)
    {
        fact*=i;
    }return fact;
}
