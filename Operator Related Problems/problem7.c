
/*7. Program that will declare and initialize an integer and a floating point number. Then it will
perform floating to integer and integer to floating conversions using
(a) Assignment operation
(b) Type casting
Sample input Sample output
-150 123.125 Assignment: 123.125000 assigned to an int produces 123
Assignment: -150 assigned to a float produces -150.000000
Type Casting: (float) -150 produces -150.000000
Type Casting: (int) 123.125 produces -123*/
#include<stdio.h>
int main()
{

    int A;
    float B;
    int X;
    float Y;
    printf("Enter a integer number:");
    scanf("%d",&A);
    printf("Enter a floating number:");
    scanf("%f",&B);
    A=X;
    B=Y;
    printf("%d assigned to a float produces: %f\n",A,X);
    printf("%f Enter a integer number:%d",B,Y);



}
