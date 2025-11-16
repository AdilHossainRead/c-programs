/*7. Write a program (WAP) that will run and show keyboard inputs until the user types an ’A’
at the keyboard.
Sample input
X
1
a
A
Sample output:
Input 1: X
Input 2: 1
Input 3: a
*/
#include<stdio.h>
int main()
{
    int i;
    char x;
    for(i=1; i>0; i++)
    {
        printf("Enter any character:");
        scanf("%c",&x);
        if(x=='A')
        {
            break;
        }else {
            printf("Input %c\n",x);
            }


    }
}
