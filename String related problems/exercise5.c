#include<stdio.h>
int main()
{
   char string[100];
   printf("Enter the string: ");
   fgets(string,100,stdin);
   int a_count=0,e_count=0,i_count=0,o_count=0,u_count=0;
   int length=strlen(string)-1;
   printf("string length is: %d\n",length);
   for(int i=0; i<length;i++)
   {
       if(string[i]=='a'||string[i]=='A')
       {
         a_count++;
       }if(string[i]=='e'||string[i]=='E')
       {
         e_count++;
       }if(string[i]== 'i'||string[i]=='I')
       {
         i_count++;
       }if(string[i]=='o'||string[i]=='O')
       {
         o_count++;
       }if(string[i]=='u'||string[i]=='U')
       {
         u_count++;
       }

   }printf("number of A/a is: %d\n",a_count);
   printf("number of  E/e is: %d\n",e_count);
   printf("number of I/i is: %d\n",i_count);
   printf("number of O/o is: %d\n",o_count);
   printf("number of u/u is: %d\n",u_count);



}
