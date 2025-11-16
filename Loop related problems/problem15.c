
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
Student 2 : F*/
#include<stdio.h>
int main()
{

    float a,hw,ct,f,n,mt,tf;
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
        float Attendance_mark=(a/5)*100;
        float Assignments_mark=(hw/10)*100;
        float Class_Tests_mark=(ct/15)*100;
        float Midterm_mark=(mt/30)*100;
        float Final_mark=(tf/40)*100;
        int total_mark=(Attendance_mark+Assignments_mark+Class_Tests_mark+Midterm_mark+Final_mark);
        printf("Sudent%d result:",i);
        if(100>=total_mark>=90){
            printf("A\n");
        }else if(89<=total_mark>=86){
            printf("A-\n");
        }else if(85<=total_mark>=82){
            printf("B+\n");
        }else if(81<=total_mark>=78){
            printf("B\n");
        }else if(77<=total_mark>=74){
            printf("B-\n");
        }else if(73<=total_mark>=70){
            printf("C+\n");
        }else if(69<=total_mark>=66){
            printf("C\n");
        }else if(65<=total_mark>=62){
            printf("C-\n");
        }else if(61<=total_mark>=58){
            printf("D+\n");
        }else if(total_mark>=55){
            printf("D\n");
        }else {
            printf("F\n");
        }



    }







}
