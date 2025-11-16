/*Write a C program according to the following:

i) Write a function “IsEven” that will take an integer as parameter and determine whether it is
even or not. If the integer is even, then the function will return 1. Otherwise, it will return 0.
ii) Write a function “ComputeEvenSum” that will take an array of integers and n as parameters.
n is the number of values in the array. It computes the sum of the even numbers in that
array and returns the sum. You must use “IsEven” function for even checking.
iii) In main( ) function, declare and initialize the array and any other variables as needed. Then
call the function “ComputeEvenSum” with appropriate parameters and finally display the
returned value.*/
#include<stdio.h>
int IsEven(int number)
{
    if(number%2==0)
        return 1;
    else
        return 0;
}
int ComputeEvenSum(int arr[],int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if (IsEven(arr[i]))
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the number of arr:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter %d number element:",i+1);
        scanf("%d",&arr[i]);
    }
    int sum;
    sum=ComputeEvenSum(arr,n);
    printf("Even_sum is:%d",sum);

}
