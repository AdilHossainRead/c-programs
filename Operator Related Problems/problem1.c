/*1. Program that will take two numbers X and Y as inputs, then calculate and print the values
of their addition, subtraction, multiplication, division (quotient and reminder).
Sample input (X,Y) Sample output
5 10 Addition: 15
Subtraction: -5
Multiplication: 50
Quotient : 0
Reminder: 5
-5 10.5 Addition: 5.5
Subtraction: -15.5
Multiplication: -52.5
Quotient: 0
Reminder: -48*/
#include<stdio.h>
int main()
{
    int X,Y;
    int Addition,Subtraction,Multiplication,Quotient,Reminder;
    printf("Enter two number: ");
    scanf("%d %d",&X,&Y);
    Addition=X+Y;
    Subtraction=X-Y;
    Multiplication=X*Y;
    Quotient=X/Y;
    Reminder=X%Y;
    printf("Addition=%d\n",Addition);
    printf("Subtraction=%d\n",Subtraction);
    printf("Multiplication=%d\n",Multiplication);
    printf("Quotient=%d\n",Quotient);
    printf("Reminder=%d\n",Reminder);


    getchar();




}
