/*Write a C program to print the following pattern. Take n as user input where n is odd and n>=5.
Sample input n=5
Sample output
    1
   13
  135
 1351
13513*/
#include<stdio.h>
int main()
{
    int n,row,col;
    printf("Enter number n= ");
    scanf("%d",&n);
    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n-row; col++)
        {
            printf(" ");

        }
        int p=1,x=1;
        for(col=1; col<=row; col++)
        {
            if(p<=n)
            {
                printf("%d",p);
                p+=2;
            }
            else
            {
                printf("%d",x);
                x+=2;
            }
        }

        printf("\n");
    }




}
