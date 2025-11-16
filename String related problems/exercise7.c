/*Consider the following string declaration:
Char str[55]=“I love spl. Uiu has some good labs for spl.”;
Write a C program that will replace each occurrence of the word "spl" with "dsa" and print out the
resulting text. You cannot use any library functions.*/
#include<stdio.h>
int main()
{
    char str[55]="I love spl. uiu has some good labs for spl";
    for(int i=0;str[i]!='\0';i++)
    {
       if (str[i] == 's' && str[i + 1] == 'p' && str[i + 2] == 'l')
       {
           (str[i] == 'u' && str[i + 1] == 'i' && str[i + 2] == 'u');
       }
    }
    for(int i=0;str[i]!='\0';i++)
    {
      printf("%c",str[i]);
    }
}
