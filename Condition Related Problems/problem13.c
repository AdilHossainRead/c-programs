#include<stdio.h>
int main()
{
    int number,x,y=0,z;
    printf("Enter any number:");
    scanf("%d",&number);
    z=number;
    while(number>0)
    {
       x=number%10;
       y=y*10+x;
       number=number/10;
    }
    printf("The riverse numer is %d\n",y);
    if(z==y){
        printf("Yes,number is Palindrome\n");
    }else{
    printf("NO\n");
    } int sum = 0;
    int position = 0;

    while(z>0)
    {
       int digit=z%10;
       sum+=digit;
       number=number/10;
    }
     printf("sum is %d\n",sum);

    if (sum % 2 == 0) {
        printf("sum is a even Number\n");
    } else {
        printf("sum is odd Number.\n");
    }

}

