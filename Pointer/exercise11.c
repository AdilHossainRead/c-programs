#include<stdio.h>
int main()
{
    int x=10;
    int *ptr;
    ptr=&x;
    printf("X=%d",*ptr);
    printf("X=%d",x);
    printf("X=%d",&ptr);
}
