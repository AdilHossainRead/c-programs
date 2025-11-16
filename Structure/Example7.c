#include<stdio.h>
struct cricketer
{
   char name[50];
   char country[50];
   char type[20];
   int total_match_played;
   int wicket_take[100];
   int run_score[100];
   float over_all_perfomancen_score;

};
int main()
{
   int n;
   printf("Enter the player number: ");
   scanf("%d",&n);
   int player[n];
   struct cricketer player[n];
   for(int i=0;i<n;i++)
   {
       printf("Enter %d number data: ",i+1);
       printf("Enter player name:");
       scanf("%s",&player[i].name);
       printf("Enter player country:");
       scanf("%s",&player[i].country);

        scanf("%s",&player[i].name);
   }
}
