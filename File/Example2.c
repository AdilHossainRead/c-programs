#include<stdio.h>
int main()
{
    FILE*file;
    char name[50]="Adil Hossain Read";\
    int length=strlen(name);
    file=fopen("example2.txt","r");
    if(file==NULL)
    {
        printf("File dose not exist");
    }
    else{
        printf("File file is open");
        for(int i=0;i<length;i++)
        {
            fputc(name[i],file);
        }
    }fclose(file);
}
