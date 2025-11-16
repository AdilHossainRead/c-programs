
/*5. Write a program in C to find the reverse of a string. **
Sample Input               Sample Output
“My name is Andy”          “ydnA si eman yM”
“Abc 123 7&*&*”            “*&*&7 321 cbA”*/

#include<stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter the string: ");
    gets(str);
    printf("%s\n",strrev(str));
    int n=strlen(str);
    printf("String length is n=%d\n",n);
    for(int i=n;i>=0;i--)
    {
        printf("%c",str[i]);
    }

}
