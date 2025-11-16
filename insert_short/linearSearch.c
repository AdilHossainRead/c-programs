#include<stdio.h>
int main()
{
    int n,i,key=55,poss=-1;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter value of key: ");
    scanf("%d",&key);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter %d number elements:",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            poss=i;
            printf("possition=%d\n",poss);
            break;

        }
    }
    printf("possition=%d\n",poss);
    if(poss==-1){
        printf("value was not founde\n");
    }
    else
        {
            printf("value was founded");
        }


}
