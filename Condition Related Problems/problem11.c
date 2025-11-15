/*11. Program that will take the final score of a student in a particular subject as input and find
his/her grade.
Marks Letter Grade Marks Letter Grade Marks Letter Grade
90-100 A 70-73 C+ Less than 55 F
86-89 A- 66-69 C
82-85 B+ 62-65 C78-81 B 58-61 D+
74-77 B- 55-57 D
Sample input Sample output
91.5 Grade: A
50 Grade: F*/
#include<stdio.h>
int main()
{
    int A;
    printf("The final score of a student in a particular subject: ");
    scanf("%d",&A);
    if(A>101){
        printf("Invalid ");}
        else if(A<=100&&A>=90){
        printf("A");
    }else if(A>=86){
        printf("A-");
    }else if(A>=82){
        printf("B");
    }else if(A>=78){
        printf("B");
    }else if(A>=74){
        printf("B-");
    }else if(A>=70){
        printf("C+");
    }else if(A>=66){
        printf("c");
    }else if(A>=62){
        printf("C-");
    }else if(A>=58){
        printf("D+");
    }else if(A>=55){
        printf("D");
    }else if(A<55){
        printf("F");
    }
}
