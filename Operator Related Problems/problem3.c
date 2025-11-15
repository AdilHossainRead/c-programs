
/*3. Program that will take two numbers (a, b) as inputs and compute the value of the equation
– (Without using math.h)
X = (3.31 * a2 + 2.01 * b3
) / (7.16 * b2 + 2.01 * a3
)
Sample input (a, b) Sample output
5 10.5 X = 2.315475
100 -250 X = -12.766287*/

#include<stdio.h>
int main()
{
  float A,B;
  float X;
  printf("Enter two number:");
  scanf("%d &d",&A,&B);
  X=(3.31*A*A+2.01*B*B*B)/(7.16*B*B+2.01*A*A*A);
  printf("X=%f",X);
  getchar();


}
