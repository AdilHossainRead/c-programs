/*10. Write a program (WAP) that will give the sum of first Nth terms for the following series.
1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, …….
Sample input Sample output
2 Result: -1
3 Result: 2
4 Result: -2 Adil
*/
#include<stdio.h>
int main()
{
    int n,i,sum,Odd=0,even=0;
    printf("Enter the number n=");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        if(i%2!=0){
            Odd+=i;
        }else{
        even+=i;
        }
    }sum=Odd-even;
    printf("%d",sum);

}
