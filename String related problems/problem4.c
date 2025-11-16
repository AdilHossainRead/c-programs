/*4. Write a program in C to count the number of words in a string.
Sample Input                 Sample Output
“My name is andy”             4
“Abc 123 7&*&*”               3
*/
#include<stdio.h>
#include <string.h>
int main()
{
    int i=0,word=0;
    char str[100];
    printf("Enter the string:");
    gets(str);
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
           word++;
        }
        i++;
    }word++;
    printf("Words = %d",word);
}
