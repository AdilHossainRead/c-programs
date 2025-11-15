/*6. Program that will multiply and divide a number X by Y. (Use *= and /= operators)
Sample input(X,Y) Sample output
56 10 Multiplication: 560
Division: 5
-56 -10 Multiplication: 560
Division: 5*/
#include<stdio.h>
int main()
{
    int X,Y,A,B;
  printf("Enter two number:");
  scanf("%d%d",&X,&Y);
  A=X*Y;
  B=X/Y;
  printf("Multiplication value= %d\n",A);
  printf("Division value= %d\n",B);
  getchar();
}
