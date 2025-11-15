/*5. Program that will increment and decrement a number X by Y. (Use += and -= operators)
Sample input(X,Y) Sample output
5 10 Incremented Value: 10
Decremented Value: -5
-5 5 Incremented Value: 0
Decremented Value: -10*/
#include<stdio.h>
int main()
{
    int X,Y,A,B;
  printf("Enter two number:");
  scanf("%d%d",&X,&Y);
  A=X+Y;
  B=X-Y;
  printf("Increment value= %d\n",A);
  printf("Decrement value= %d\n",B);
  getchar();
}
