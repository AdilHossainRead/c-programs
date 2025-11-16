/*7. Function to calculate the sum of n numbers coming from the console and stored in an array.
Sample input Sample output
3
80 33 27
Sum In Function: 140
Sum In Main: 140
2
100 -100
Sum In Function: 0
Sum In Main: 0
*/
#include<stdio.h>
int function_sum(int arr[],int n);
int main()
{
    int n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter %d number element: ",i+1);
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("sum in main function %d",sum);
   int y=function_sum( arr,n);

   printf("sum in function %d",y);

}
int function_sum(int arr[],int n)
{
   int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
    }
    return sum;
}

