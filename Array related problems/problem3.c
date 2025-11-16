/*WAP that will take n integer numbers into an array, and then sum up all the even integers
in that array.
Sample input Sample output
5
1 2 3 4 5
6
6
2 8 3 9 0 1
10*/

#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the number of array: ");
    scanf("%d",&n);
    int array[n];
    for(i=0; i<n; i++)
    {
        printf("%d number element = ",i);
        scanf("%d",&array[i]);

    }
    printf("Elementf of array:");
    for(i=0; i<n; i++)
    {
        printf("%d,",array[i]);
        if(array[i]%2==0)
        {
            sum+=array[i];
        }
    }
    printf("sum=%d",sum);

}
