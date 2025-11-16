/*trcmp(s1,s2)

*/
#include<stdio.h>
int main()
{
    char source[]="God can and ";
    char destination[]="God will";
    printf("..%d\n",strcmp(source,destination));
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "Hi";

// Compare str1 and str2, and print the result
    printf("%d\n", strcmp(str1, str2));  // Returns 0 (the strings are equal)

// Compare str1 and str3, and print the result
    printf("%d\n", strcmp(str1, str3));  // Returns -1 (the strings are not equal)
    printf("%d\n", strcmp(str3, str1));  // Returns 1 (the strings are not equal)
    char s1[40]="CSE-I11M";
    char s2[40]="I am a UIUan";
    printf(".........%d",strcmp(s2,s1));



}
