
/*Program that will calculate the circumference of a circle having radius r.
Area, A = 2 * Pi * r
Sample input (r) Sample output
5 Area: 31.4
10.5 Area: 65.94
*/
#include<stdio.h>
int main()
{
    float Area,A,pi;
    pi=3.1416;
    printf("Enter readian: ");
    scanf("%f",&A);
    Area=2*pi*A;
    printf("Area=%f",Area);
    getchar();
}
