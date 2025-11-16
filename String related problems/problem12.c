
#include<stdio.h>
#include<string.h>
int main()
{

    char str1[100]="Hello World",str2[100]="Programming is fun", str3[100];
//gets(str1);
//scanf("%s",str2);
    strncpy(str3,str1,8);
    printf("1 %s\n",str3);
    strncat(str2,str3,4);
    printf("2 %s\n",str2);
    strcpy(str3,str2);
    printf("3 %s\n",str3);
    strncat(str3,str1, 3);
    printf("4 %s\n",str3);
    if (strcmp(str2,str3)>0)
        {
    strncpy(str1,str3,2);
    printf("5 %s\n",str1);}

    else
    {
        strncpy(str2,str3,2);
        printf("6 %s",str2);
    }
}
