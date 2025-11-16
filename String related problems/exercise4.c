#include<stdio.h>
#include<string.h>
int main()
{
    char source[20];
    fgets(source,20,stdin);
    //gets(source);
    printf("%s",source);
    int x = strlen(source)-1;
    printf("string lenght is: %d\n",x);
    printf("reverse string: %s",strrev(source));
    return 0;


}
