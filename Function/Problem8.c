/*8. Function that takes an array of n integer numbers as input and prints them in reverse order.
Sample input Sample output
3
4 8 2
2 8 4
7
5 12 34 8 43 21 9
9 21 43 8 34 12 5*/
#include<stdio.h>
int reverse_order(int arr[],int n);
int main()
{
    int i,n;
    printf("Enter the number of arr: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d number element: ",i+1);
        scanf("%d",&arr[i]);
    }
    reverse_order(arr,n);
}
int reverse_order(int arr[],int n)
{
    printf("Reverse order number :\n");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
}
