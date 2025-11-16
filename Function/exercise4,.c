//creating and useing function
//finding thr maximum value
#include<stdio.h>
int max(int a, int b,int c);//function prototype
int main()
{
    int x,y,z;
    printf("Enter three value: ");
    scanf("%d %d%d",&x,&y,&z);
    int m=max(x,y,z);
    printf("maximum number = %d",m);


}
 max(int a, int b,int c)
{

    if(a>b && a>c)
    {
        return a;
    }
    else if(b>a && b>c)
    {
        return b;
    }
    else
    {
        return c;
    }



}
