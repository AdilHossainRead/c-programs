/*8. WAP that will take n integers into an array, and then search a number into that array. If
found then print its index. If not found then print “NOT FOUND”.
Sample input Sample output
8
7 8 1 3 2 6 4 3
3
FOUND at index position: 3, 7
8
7 8 1 3 2 6 4 3
5
NOT FOUND*/
#include<stdio.h>
int main()
{
    int n,i,value,possition=-1;
    printf("Enter the number of array:");
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++){
        printf("Enter %d number element:",i);
        scanf("%d",&array[i]);
    }
    printf("The character of array: ");
    for(i=0;i<n;i++){
        printf(" %d\n",array[i]);
    }
    printf("Enter surching value:");
    scanf("%d",&value);
    for(i=0;i<n;i++){
        if(value==array[i]){
             possition=i+1;
             break;
        }
    }
    if(possition==-1){
        printf("Not found");
    }else{
    printf("The possition of %d is %d",value,possition);
           }


}
