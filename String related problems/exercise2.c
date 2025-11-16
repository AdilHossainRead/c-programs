/*strcat(destination, source)
	🡪 Concatenate source string to destination string and the result 	is stored in the destination string.
strncat(destination,source,n)-> Concatenates first n characters of source string to destination string.
*/
#include<stdio.h>
int main()
{
    char source[]="God can and ";
    char destination[]="God will";
    strcat(source,destination);
    printf("%s.\n",source);
    puts(source);

}
