/*2. Function to print an input character value.
Sample input                      Sample output
3                                 Value received from main: 3
A                                 Value received from main: A
*/
#include<stdio.h>
void ReceiveVlue(int number);
int main()
{
    int a;
    printf("Enter a integer number:");
    scanf("%d",&a);
    ReceiveVlue(a);
}
ReceiveVlue(int number)
{
  printf("Value received from main:%d",number);
}
