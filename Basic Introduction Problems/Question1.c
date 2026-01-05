#include<stdio.h>
int main()
{
    int base,height;
    printf("enter height; ");
    scanf("%d",&height);
    printf("enter base; ");
    scanf("%d",&base);
    base+=(2*2);
    height+=(2*2);
    printf("with path base will be %d \n",base);
    printf("with path base will be %d \n",height);
    float area=.5*base*height;
    printf("Area is %f",area);
}
