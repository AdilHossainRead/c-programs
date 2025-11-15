/*4. Program that will increment and decrement a number X by 1 inside the printf function.
(Use ++ and - - operators)
Sample input(X) Sample output
5 X++ : 5
++X : 6
X- - : 5
--X : 4
-5 X++ : -5
++X : -4
X- - : -5
--X : -6*/

#include<stdio.h>
int main()
{
    int X,Y;
  printf("Enter any number:");
  scanf("%d",&X);
  //X=5;
  printf("%d\n",X);
  X++;
  printf("%d\n",X);
  ++X;
  printf("%d\n",X);
  X--;
  printf("%d\n",X);
  --X;
  printf("%d\n",X);

}

