/*6. Function to calculate the sum of n numbers coming from the console.
Sample input Sample output
80 33 27 Sum In Function: 140
Sum In Main: 140
100 -100 Sum In Function: 0
Sum In Main: 0
*/
#include<stdio.h>
int sum(int count);
int main()
{
   int n;
   printf("Enter how many number of sum:");
   scanf("%d",&n);
   int result=sum(n);
   printf("Sum in function %d",result);
}
int sum(int count)
{
    int i=1,num;
    int sum=0;
    for(i=1;i<=count;i++)
    {
        printf("Enter the numbr %d: ",i);
        scanf("%d",&num);
        sum+=num;
    }return sum;
}
