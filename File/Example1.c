
#include<stdio.h>
int main()
{
    char p;
    FILE*f;
    f=fopen("example1.txt","r");
    if(f==NULL)
    {
        printf("File dose not exist");
    }
    else{
        while ((p = fgetc(f)) != EOF) {
        printf("%c",p);

    }
           // fprintf(f,("%d"),5);//write method
          printf("\nFile file is open");
    }fclose(f);
}
