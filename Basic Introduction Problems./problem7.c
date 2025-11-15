/*
7. Program that will receive the values of an integer, a floating point number, a character from
the keyboard and print those values.
Sample input Sample output
5
3.141593
A
The integer value: 5
The floating point value: 3.141593
The character value: a
100 1.618 z The integer value: 100
The floating point value: 1.618000
The character value: z
*/
#include<stdio.h>
 int main()
 {
     int A;
     float B;
     char C;
     printf("Enter an integer number:");
     scanf("%d",&A);
     printf("Enter a floating number:");
     scanf("%f",&B);
     printf("Enter a character:");
     //scanf("%c\n",&C);
     scanf("%c", &C);

     printf("integer value:%d\n",A);
     printf("floating value:%f\n",B);
     printf("The character value:%c\n",C);

     getchar();


 }
