#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
}
int find_min_index(int arr[],int n, int starting_index)
{
    int minimum_value=arr[starting_index];
    int minimum_index=starting_index;

    for(int i=starting_index;i<n;i++)
    {
        if(arr[i]<minimum_value)
        {
            minimum_value=arr[i];
            minimum_index=i;
        }
    }
    return minimum_index;
}
int find_max_index(int arr[],int n, int starting_index)
{
    int maximum_value=arr[starting_index];
    int max_index=starting_index;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>maximum_value)
        {
            maximum_value=arr[i];
            max_index=i;
        }
    }
    return max_index;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_short_assending_order(int arr[],int n)
{
    int minimum_index;
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        arr[i] = arr[minimum_index];
        arr[minimum_index] = temp;
        printArray(arr,n);
        printf("Swapped: %d %d\n", arr[min_index], arr[i]);
    }
}

void selection_short_descending_order(int arr[],int n)
{
    for(int i=0;i<n;i++)

}

int main()
{
    int size=8;
    int array[]={7,2,6,5,4,8,1,9};
    print_array(array,size);
}
