
#include<stdio.h>
struct customer
{
    char name[100];
    int id;
    int shopping;
    float cost[];

};
int main()
{
    int n;
    printf("Enter number of customer: ");
    scanf("%d",&n);
    struct customer student[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter student%d data:\n",i+1);
        printf("Enter student name:");
        scanf("%s",&student[i].name);
        printf("Enter student Id:");
        scanf("%d",&student[i].id);
        printf("Enter student number of shopping:");
        scanf("%d",&student[i].shopping);
        printf("Enter student cost money:");
        for(int j=0;j<student[i].shopping;j++)
        {
          //printf("Enter %dth shopping",j+1);
          scanf("%f",student[i].cost[j]);
        }

    }
    for(int i=0;i<n;i++)
    {
        float total_cost=0;
        for(int j=0;j<=student[i].shopping;j++)
        //for (int j = 1; j <= customers[i].times_shopped; j++)
        {
            total_cost+=student[i].cost[j];

        }
    }

}
