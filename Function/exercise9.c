#include<stdio.h>
void printarr(int arr[],int size)
{
   for(int i=0;i<size;i++)
   {
      printf("%d",arr[i]);
   }printf("\n");
}
int main()
{
    int arr1[]={1,2,3,4,5,6};
    int arr2[]={5,6,7,8};
   // printarr(arr[],int size);
    printarr(arr1,6);
    printarr(arr2,7);
}

