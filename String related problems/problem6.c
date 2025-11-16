/*6. Write a program in C to convert lowercase string to uppercase.
Sample Input                      Sample Output
“My name is andy”                “MY NAME IS ANDY”
“& I am 20 years old”             “& I AM 20 YEARS OLD”
*/
#include<stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i;
    printf("Enter the string: ");
    gets(str);
    int n=strlen(str);
    //printf("String length is n=%d\n",n);
    while(str[i]!='\0')
    {

         str[i] = toupper(str[i]);
         printf("%c",str[i]);
         i++;

    }
}
