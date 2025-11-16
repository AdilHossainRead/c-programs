/*1. Write a program in C to find the length of a string without using any library function.
Sample Input Sample Output
“My name is andy” 15
“Abc 123 7&*&*” 13
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100];
    char str2[100];
    char str3[100];
    //printf("Enter 1st string:");
    //scanf("%s",str1);
    //printf("String length is: %d\n",strlen(str1));
    printf("Enter 2nd string:");
    gets(str2);
    printf("String length is: %d\n",strlen(str2));
    printf("Enter 3rd string:");
    fgets(str3,100,stdin);
    printf("String length is: %d\n",strlen(str3));



}
