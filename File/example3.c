//Write  a C program to write even, odd numbers to separate file
#include<stdio.h>
int main()
{

    FILE*inputfile=fopen("numbr.txt","r");
    FILE *evenFile=fopen("even.txt","w");
    FILE *oddFile =fopen("odd.txt","w");


        int arr[100];
        char p;
        int j=0;

        while ((p = fgetc(inputfile)) != EOF) {
            if(p!='\n'){
               arr[j++]=((int)p)-((int)'0');
            }

        }
        for(int i=0;i<10;i++)
        {
            if(arr[i]%2==0)
            {
                fprintf(evenFile,"%d\n",arr[i]);
            }else{
             fprintf(oddFile,"%d\n",arr[i]);
            }
        }

    fclose(inputfile);
    fclose(evenFile);
    fclose(oddFile);

}
