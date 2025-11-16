/*3. Function to determine if a number is even or odd.
Sample input Sample output
3 odd
8 even*/
#include<stdio.h>
int chake(int number);
int main()
{
    int number1;
    int X;
    printf("Enter an integer number:");
    scanf("%d",&number1);
    X=chake(number1);
    //printf("X");
    if(X==1){
        printf("The number is even");
    }else if(X==0){
    printf("The number is odd");
    }

}
chake(number)
{
    if(number%2==0)
    {
        return 1;
    }else{
    return 0;
    }

}

