/*write a down program that take a small latter
as input and will prints previous latter */
#include<stdio.h>
int main()
{
    char ch;
    printf("Enter any characrer :");
    scanf("%c",&ch);
    int X=ch;
    printf("%c",X-1);
    getchar();
}
