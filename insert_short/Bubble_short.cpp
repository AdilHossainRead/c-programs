#include<stdio.h>
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
}
void swap_value(int *x, int *y)
{
    int temp=*x;
    *y=*x;
    *x=temp;
}
void Buble_Shorting_Assending_Order(int arr[],int n)
{
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        printf("\n");
        printf("Print array ascending order:");
        printArray(arr,n);
    }
    }

}
void Buble_Shorting_Descending_Order(int arr[],int n)
{

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
    {
        if(arr[i]<arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        printf("\n");
        printf("Print array descending order:");
        printArray(arr,n);
    }
}
int main()
{
    int n=8;
    int arra[]={9,8,7,6,5,4,3,44};
    printArray(arra,n);
    Buble_Shorting_Assending_Order(arra,n);
    Buble_Shorting_Descending_Order(arra,n);
}
