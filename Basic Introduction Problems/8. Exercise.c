
/*Program that will take three integer numbers from keyboard but assign only the first and
last inputs to variables and skip any assignment of the middle one.
Sample input Sample output
20 50 100 First Value = 20, Last Value = 100
33 75 22 First Value = 33, Last Value = 22*/
#include<stdio.h>
int main()
{
   int a,b,c;
   printf("Enter three number:");
   scanf("%d %d %d",&a,&b,&c);
   printf("First number=%d\n",a);
   printf("Last number=%d\n",c);
   getchar();
}
