/*Write a C Program to store the following information about international cricketers and find the

“Cricketer of the Year”:
i) Create a structure named Cricketer with name (string of length 50), country (string of length
50), cricketer type (string of length 10), wickets taken in the last 30 matches (in an array),
runs scored in the last 30 matches (in an array), total match played in the last year (int),
and overall performance score (float).
a. There are only 2 types of cricketers: “bowler” and “batsman”. So, the cricketer type in
the structure stores only one of these two values.
ii) In the main( ) function,
a. Take input for 100 Cricketers from the user. DO NOT take the overall performance as
input.
b. Additionally, calculate the overall performance of each cricketer in the following way:
i. If the cricketer is a “bowler”: total wickets taken in the last 30 matches ÷ total matches
played in the last year
ii. If the cricketer is a “batsman”: total runs scored in the last 30 matches ÷ total
matches played in the last year
c. Find and display the information of the “Cricketer of the Year” who has the highest
overall performance.
*/
#include<stdio.h>
#include<string.h>
struct player
{
    char name[50];
    char country[50];
    char cricketer_type[10];
    int match;
    int wickets[100];
    int runs[100];
    //int total_matches;
    float performance_score;
};
int main()
{
    int n;
    printf("Enter the number of players:");
    scanf("%d",&n);
    fflush(stdin);
    struct player pla[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter %d player data:\n",i+1);
        printf("Enter the player name:");
        //scanf("%s",&pla[i].name);
        gets(pla[i].name);
        //fgets(pla[i].name, 50, stdin);
        printf("Enter the player country: ");
        scanf("%s",&pla[i].country);
        //fgets(pla[i].country, 50, stdin);
        //pla[i].country[strcspn(pla[i].country, "\n")] = 0;
        printf("Enter the cricketer_type:");
        scanf("%s",&pla[i].cricketer_type);
        fflush(stdin);
        printf("Enter how many match played cricketer:");
        scanf("%d",&pla[i].match);
        printf("Enter the wickets taken in the %d matches:",pla[i].match);
        for(int j=0; j<pla[i].match; i++)
        {
            for(int j=0; j<pla[i].match; i++)
            {
                scanf("%d",&pla[i].wickets);
            }

        }
        printf("Enter the runs taken in the %d matches:\n",pla[i].match);
        for(int j=0; j<pla[i].match; i++)
        {
            for(int j=0; j<pla[i].match; i++)
            {
                scanf("%d",&pla[i].runs);
            }

        }
    }
    printf("last 30 match total runs player %d is:",i+1);
    for(int i=0; i<n; i++)
    {
        int total_runs=0;

        for(int J=pla[i].match;j>pla[i].match-30;j--)
        {
            total_runs+=pla[j].runs;
        }
        printf("player %d total runs is %d",i+1,total_runs)

    }
    printf("last 30 match total weicket player %d is:",i+1);
    for(int i=0; i<n; i++)
    {
        int total_runs=0;

        for(int J=pla[i].match;j>pla[i].match-30;j--)
        {
            total_weiket+=pla[j].weikets;
        }



}
