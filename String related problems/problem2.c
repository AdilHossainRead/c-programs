/*2. Write a program in C to concatenate two strings without using any library function.
Sample Input                     Sample Output
“My name ”
“is andy”
                                 “My name is andy”
“123abc”
“*A*B”
                                 “123abc*A*B”
*/
#include<stdio.h>
#include <string.h>
int main()
{
    char dest[100]="My namel is";
    char source[100]="Adil Hossain.";
    strcat(dest,source);
    printf("%s\n", dest);
    strncat(dest,source,4);
    puts(dest);
    printf("%s", dest);
}
