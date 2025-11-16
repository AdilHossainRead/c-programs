/*4. Write a program (WAP) that will take N numbers as inputs and compute their average.
(Restriction: Without using any array)
Sample input Sample output
3
10 20 30.5
AVG of 3 inputs: 20.166667
2
22.4 11.1
AVG of 2 inputs: 16.75000 Adil*/
#include<stdio.h>
int main()
{
    int n,i;
    float sum=0,avg,num;
    printf("Enter how many number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i==1){
         printf("Enter %dst number:",i);
        }else if(i==2){
         printf("Enter %dnd number:",i);
        }else if(i==3){
         printf("Enter %drd number:",i);
        }else {
         printf("Enter %dth number:",i);
        }
        //printf("Enter %d th nunber= ",i);
        scanf("%f",&num);
        sum=sum+num;
    }printf("sum=%.2f",sum);
    avg=sum/n;
    printf("Avg=%.2f",avg);
}
