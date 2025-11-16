/*Rahim is suffering from stuttering. Stuttering / stammering is a speech disorder, which causes
involuntary repetitions of vowels, phrases, etc. Write a program that will take a sentence said
by Rahim and store that into a string. The program will also correct the sentence by removing the
repetitive vowels.

Sample input string
He is aaaa smaart boy.
IIIIIII will geeeeet great maarks.
Sample output string
He is a smart boy.
I will get great marks.
*/
#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter the string:");
    gets(str);
    int n=strlen(str);
    printf("string length is:%d\n",n);
    for(int i=0;str[i]!='\0';)
    {
        if(str[i]==str[i+1])
        {
            int j=i+1;
            int k=i;
            for(;str[j]!='\0';j++){
                str[k++]=str[j];
            }
            str[k]='\0';
        }
        else{
            i++;
        }
    }
    puts( str);
}
