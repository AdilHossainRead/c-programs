#include<stdio.h>
struct person
{
    int age;
    int id;
    float salary;
};
int main()
{
    int n;
    printf("Enter number of pepole:");
    scanf("%d",&n);
    struct person person[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter information %d\n",i+1);
        printf("Enter age: ");
        scanf("%d",&person[i].age);
        printf("Enter id: ");
        scanf("%d",&person[i].id);
        printf("Enter salary: ");
        scanf("%f",&person[i].salary);

    }
    for(int i=0;i<n;i++)
    {
        printf("Information person %d\n",i+1);
        printf("age :%d\n", person[i].age);
        printf("id :%d\n",person[i].id);
        printf("salary: %f\n",person[i].salary);
    }
}
