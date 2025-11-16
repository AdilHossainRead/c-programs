/*4. Function to determine if a number is positive, negative or zero.
Sample input Sample output
3 positive
-5 negative
0 zero*/
#include<stdio.h>
int determine(int number);
int main()
{
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    int y=determine(x);
    if(y==1)
    {
        printf("Positive number.");
    }
    else if(y==-1)
    {
        printf("Negative number.");
    }
    else if(y==0)
    {
        printf("number is zero.");
    }
}
determine(number)
{
if(number>0)
    return 1;
else if(number<0)
    return -1;
else if(number==0)
    return 0;

}

