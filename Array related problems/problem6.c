/*6. WAP that will take n integer numbers into an array, and then find the maximum -
minimum among them with its index position.
Sample input Sample output
5
1 2 3 4 5
Max: 5, Index: 4
Min: 1, Index: 0
6
2 8 3 9 0 1
Max: 9, Index: 3
Min: 0, Index: 4*/
#include<stdio.h>
int main()
{
    int i,n,max;
    printf("Enter the number the array:");
    scanf("%d",&n);
    int array[n];
    for(i=0; i<n; i++)
    {
        printf("%d number element=",i);
        scanf("%d",&array[i]);
    }
    printf("The elements are:");
    for(i=0; i<n; i++)
    {
        printf("%d,",array[i]);
    }
    printf("\n");
    max=array[0];
    for(i=1; i<n-1; i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }

    }
    printf("Max number=%d",max);


}
