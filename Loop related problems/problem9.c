
/*9. Write a program (WAP) that will find the grade of N students. For each student, it will
take the marks of his/her the attendance (on 5 marks), assignment (on 10 marks), class
test (on 15 marks), midterm (on 50 marks), term final (on 100 marks). Then based on the
tables shown below, the program will output his grade.
Attendance (A) 5%
Assignments (HW) 10%
Class Tests (CT) 15%
Midterm (MT) 30%
Final (TF) 40%
Marks Letter Grade Marks Letter Grade Marks Letter Grade
90-100 A ;70-73 C+ ;Less than 55 F
86-89 A- ;66-69 C;
82-85 B+; 62-65 C;78-81 B ;58-61 D+
74-77 B- ;55-57 D;
Sample input (A,HW,CT,MT,TF) Sample output
2
5 10 15 44.5 92.5
0 7.5 5 20 55.5
Student 1 : A
Student 2 : F
Adil
*/
#include<stdio.h>
int main()
{
    float a,hw,ct,f,n;
    float mt,tf;
    printf("Enter student number:");
    scanf("%f",&n);
    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
            printf("Enter %dst student result are::",i);
        }
        else if(i==2)
        {
            printf("Enter %dnd student result are::",i);
        }
        else if(i==3)
        {
            printf("Enter %drd student result are::",i);
        }
        else
        {
            printf("Enter %dth student result are::",i);
        }
        printf("\n");
        printf("Enter attened marks:");
        scanf("%f",&a);
        printf("Enter Assignments (HW) marks:");
        scanf("%f",&hw);
        printf("Enter Class Tests (CT) marks:");
        scanf("%f",&ct);
        printf("Enter Midterm (MT)  marks:");
        scanf("%f",&mt);
        printf("Enter Final (TF)  marks:");
        scanf("%f",&tf);

        float Attendance_mark=(5.0/100)*a;
        //printf("Attendence mark : %f",Attendance_mark);
        float Assignments_mark=(10.0/100)*hw;
        float Class_Tests_mark=(15.0/100)*ct;
        float Midterm_mark=(30.0/100)*mt;
        float Final_mark=(40.0/100)*tf;
        float total_mark=(Attendance_mark+Assignments_mark+Class_Tests_mark+Midterm_mark+Final_mark);
        printf("Sudent%d result:",i);
        printf("\nTotal Marks : %f\n",total_mark);
        if(total_mark<=100  && total_mark>=90)
        {
            printf("A\n");
        }
        else if(total_mark>=86)
        {
            printf("A-\n");
        }
        else if(total_mark>=82)
        {
            printf("B+\n");
        }
        else if(total_mark>=78)
        {
            printf("B\n");
        }
        else if(total_mark>=74)
        {
            printf("B-\n");
        }
        else if(total_mark>=70)
        {
            printf("C+\n");
        }
        else if(total_mark>=66)
        {
            printf("C\n");
        }
        else if(total_mark>=62)
        {
            printf("C-\n");
        }
        else if(total_mark>=58)
        {
            printf("D+\n");
        }
        else if(total_mark>=55)
        {
            printf("D\n");
        }
        else if(total_mark<55)
        {
            printf("F\n");
        }

    }

}

