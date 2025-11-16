
/*3. Write a program (WAP) that will print following series upto Nth terms.
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, …….
Sample input Sample output
1 1
2 1, 0
3 1, 0, 1
4 1, 0, 1, 0
7 1, 0, 1, 0, 1, 0, 1
13 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1Adil*/
#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter N'th number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i%2!=0){
            printf("1,");
        }else{
        printf("0,");
        }
    }
}
