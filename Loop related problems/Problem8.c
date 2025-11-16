/*8. Write a program (WAP) that will reverse the digits of an input integer.

Sample input 13579 Sample output 97531
Sample input 4321 Sample output 1234
Adil
*/
#include<stdio.h>
int main()
{
    int i,num,count=0,temp=0,x;
    printf("Enter any number:");
    scanf("%d",&num);
    int n=num;
    while(n!=0){
        x=n%10;
        n=n/10;
        printf("%d",x);
        if(x%2==0){
            count++;
        }else if(x%2!=0){
        temp++;
        }

    }
    printf("\n");
    printf("even number are:%d\n",count);
    printf("Odd number are:%d\n",temp);
}
