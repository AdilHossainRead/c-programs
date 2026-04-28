#include<stdio.h>
int fibo(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }else
    {
       int myResult=fibo(n-1)+fibo(n-1);
       return myResult;
    }
}
int main()
{
    printf("%d", fibo(10));
}
