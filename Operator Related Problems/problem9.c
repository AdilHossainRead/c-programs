/*9. Program that will evaluate the following equations -
X = a – b / 3 + c * 2 – 1
Y = a – ( b / ( 3 + c ) * 2) - 1
Z = a – ( ( b / 3) + c * 2) - 1
Sample input (a, b, c) Sample output
9 12 3 X = 10
Y = 4
Z = -1**/
#include<stdio.h>
int main()
{
  int a=9,b=12,c=3;
  float x,y,z;
    x= a - b / 3 + c * 2 - 1;
    y = a - (b / (3 + c) * 2) - 1;
    z = a - ((b / 3) + c * 2) - 1;
  printf("%d\n",x);
  printf("%d\n",y);
  printf("%d\n",z);

}
