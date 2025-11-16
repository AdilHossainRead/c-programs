#include<stdio.h>
int max(int,int,int);
int main(){

printf("max number is :%d\n",max(12,34,1445));
printf("max number is :%d\n",max(125,3453,1445));
printf("max number is :%d\n",max(162,384,145));

}
int max(int x,int y,int z)
{
   int temp;
   if(x>y,x>z){
    temp=x;
   }else if (y>x && y>z){
   temp=y;
   }else if(z>x&&z>y){
   temp=z;
   }
}
