/*strcpy(destination, source)
	🡪 Copies the contents of source string to destination string.
strncpy(destination, source,n)-> Copy first n characters of source string to destination string.
*/
#include<stdio.h>
#include<string.h>
int main()
{
   char source[20]="God can and God will.";
   char destination[20];
   strcpy(destination,source);
   printf("%s\n",destination);
   printf("%s\n",strcpy(destination,source));

   puts(destination);
}
