/*7. WAP that will take n alphabets into an array, and then count number of vowels in that
array.
Sample input Sample output
7
AKIOUEH
Count: 5
29
UNITEDINTERNATIONALUNIVERSITY
Count: 13
*/
#include<stdio.h>
int main()
{
    int n,i,count=0;
    char A, E, I, O, U;
    //char'A','E','I','O','U';
    printf("Enter the number of array:");
    scanf("%d",&n);
    char array[n];
    for(i=0;i<n;i++){
        scanf(" %c",&array[i]);
    }printf("The character of array: ");
    for(i=0;i<n;i++){
        printf(" %C",array[i]);
    }for(i=0;i<n;i++){
        if(array[i]=='A'||array[i]=='E'||array[i]=='I'||array[i]=='O'||array[i]=='U'){
            count++;
        }
    }printf("\nCOUNT=%d",count);
}
