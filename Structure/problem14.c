
#include<stdio.h>
struct Player {
char username[50];
int vitality;
int magic;
int defense;
int attack;
};

 int isPrime(int num){
   int i;
   if(num % 1==0 &&   num % num == 0){
    return 1;
   }
   else
    return 0;

}
int digitSum(int num){

 if (num==0)
    return 0;

    return ( num % 10 ) + digitSum( num / 10 );

  }

int summation(int n){
 int i,sum=0;
 for(i=1;i<n;i++){
    sum=sum+i;
 }
   return sum;
 }

int main()
{
    struct Player p[1];
    int i;
    int num=0,sum;
    for(i=0;i<1;i++){
        fgets(p[i].username,30,stdin);
        scanf("%d", &p[i].vitality);
        scanf("%d", &p[i].magic);
        scanf("%d", &p[i].defense);
        scanf("%d", &p[i].attack);
    }
   for(i=0;i<1;i++){
   printf(" %s ", p[i].username );
   printf(" %d ",  p[i].vitality );
   printf(" %d ", p[i].magic );
   printf(" %d ",  p[i].defense );
   printf(" %d ", p[i].attack );

   }

   for(i=0;i<1;i++){
    num=num + p[i].vitality + p[i].magic + p[i].defense + p[i].attack;
   }
   printf("%d",num);
  fflush(stdin);
 int r  =  isPrime(num);
    if(r==1){
        printf("\nprime number:");
    }
    else if(r==0){
    printf("not a primee");}

    fflush(stdin);
   int lsf=isPrime(num);fflush(stdin);
   printf("\n%d",lsf);

   int j=summation(lsf);
   printf("%d",sum);

}
