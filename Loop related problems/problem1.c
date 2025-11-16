/*Write a program (WAP) that will print following series upto Nth terms.
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, …….
Sample input Sample output
2 1, 2
5 1, 2, 3, 4, 5
11 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 Adil
*/
#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d,",i);
    }
}
