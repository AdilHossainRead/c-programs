#include<stdio.h>
int binary_search(int arr[],int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            return 1;
        }

        else if(key>arr[mid])
        {
            low=mid+1;
        }
        else if(key<arr[mid])
        {
            high=mid-1;
        }
        return -1;

    }

}
int main()
{
    int key;
    printf("Please enter find value:");
    scanf("%d",&key);
    int n=9;
    int array[]= {1,2,3,4,5,6,7,8,9};
    int index=binary_search(array,n,key);
    if(index==1)
    {
        printf("found value at index :%d",index);
    }
    else
    {
        printf("value was not found.");
    }
}
