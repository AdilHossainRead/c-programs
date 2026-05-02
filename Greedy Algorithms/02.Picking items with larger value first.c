/*Picking items with larger value first
Example: val[]= [10, 10, 10, 20], wt[] = [10, 10, 10, 30], capacity = 30

If we start picking higher values, we might choose the last item (value 20, weight 30) → total value = 20.
But the better choice is to take the three items of weight 10 each → total value = 10+10+10 = 30.
So, choosing higher values first also fails.
*/

#include<stdio.h>

int fractionalKnapsack(int value[],int weight[],int capacity,int n)
{
   float profit=0;
   float currentCapacity=capacity;
   float items[n][2];
   for(int i=0;i<n;i++)
   {
       items[i][0]=value[i];
       items[i][1]=weight[i];
   }

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           float r1=value[j][0]/weight[j][1];
           float r2=value[j+1][0]/weight[j+1][1];

           if(r1<r2)
           {
               float t0= value[j][0];
               value[j][0]=value[j+1][0];
               value[j+1][0]=t0;

               float t1=weight[j][1];
               weight[j][1]=weight[j+1][1];
               weight[j+1][1]=t1;
           }
       }
   }
   for(int i=0;i<n;i++)
   {
       if()
   }
}

int main()

{

    int capacity=50;
    int value[]={60,100,120};
    int weight[]={10,20,30};
    int n=sizeof(value)/sizeof(value[0]);
    printf("Max Profit : %2f",fractionalKnapsack(value,weight,capacity,n));

}
