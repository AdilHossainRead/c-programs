/*11. Write a program (WAP) that will calculate the result for the first Nth terms of the
following series. [In that series sum, dot sign (.) means multiplication]
1^2.2 + 2^2.3 + 3^2.4 + 4^2.5 + …….
Sample input Sample output
2 Result: 14
3 Result: 50
4 Result: 130
7 Result: 924
Adil*/
#include<stdio.h>
int main()
{
    int n,x,i,sum=0;
    printf("Enter the number n=");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        x=i*i*(i+1);
        sum+=x;


    }printf("%d",sum);

}
