/*4. Write a program (WAP) that will take N numbers as inputs and compute their average.
(Restriction: Without using any array)
Sample input Sample output
3
10 20 30.5
AVG of 3 inputs: 20.166667
2
22.4 11.1
AVG of 2 inputs: 16.75000*/
#include<stdio.h>
int main()
{
    int n ;
    float a=0,avg,sum=0;
    printf("Enter how many number:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
       if (i==1)
       {printf("%d st number:",i);
        scanf("%f",&a);
        sum+=a;}
        else if (i==2)
       {printf("%d nd number:",i);
        scanf("%f",&a);
        sum+=a;}
        else if (i==3)
       {printf("%d rd number:",i);
        scanf("%f",&a);
        sum+=a;}
        else
       {printf("%d th number:",i);
        scanf("%f",&a);
        sum+=a;}

    }
    printf("sum= %.2f\n",sum);
    avg=sum/n;
    printf("Average= %.2f",avg);
}
