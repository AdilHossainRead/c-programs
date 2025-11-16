
#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
}
void insert_short(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key =arr[i];
        int j=i;
        while(j>0 && arr[j-1]>key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
        print_array(arr,n);
    }
}
void insert_short_decending_order(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        int j=i;
        while(j>0 && arr[j-1]<key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
         print_array(arr,n);
    }
}
int main()
{
    int n;
    printf("Enter size of array n=");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the number: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    print_array(arr,n);
    insert_short(arr,n);
    insert_short_decending_order(arr,n);
}
