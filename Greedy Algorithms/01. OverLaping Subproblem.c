#include<stdio.h>
int memory[100];
int fibo(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
      if(memory[n]!=0)
      {
          return memory[n];
      }
      else
      {
           int myResult=fibo(n-1)+fibo(n-1);
           memory[n]=myResult;
        return myResult;
      }
    }
}
int main()
{
    printf("%d", fibo(10));
}
