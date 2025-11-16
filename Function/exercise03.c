
#include<stdio.h>
void sum(int a,int b);
void sub(int a,int b);
void multi(int a,int b);
int main()
{
    int x, y;
    //printf("Enter two number: ");
    //scanf("%d%d",&x,&y);
  sum(x, y);
    //int y= sum;
   sub(x,y);
   multi(5,10);

}
void sum(int a,int b)
{
    printf("enter two value for sum:");
    scanf("%d %d",&a,&b);
    int sum=a+b;
    printf("The sum value is :%d\n",sum);
}
void sub(int a,int b)
{
    printf("enter two value for sub:");
    scanf("%d %d",&a,&b);
    int sub=a-b;
    printf("The sub value is :%d\n",sub);

}
void multi(int a, int b){
int multi=a*b;
printf("The multi value is :%d\n",multi);


}
