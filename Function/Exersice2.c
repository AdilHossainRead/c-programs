
#include<stdio.h>
int sum(int a,int b);//function prototype
int sub(int a,int b);
int div(int a,int b);
int multi(int a,int b);
int main()
{
    int x, y;
    printf("Enter two number: ");
    scanf("%d %d",&x,&y);
    int m=sum(x,y);//argument
    printf("sumation=%d\n",m);
    int n=sub(x,y);
    printf("subtraction=%d\n",n);
    int o=div(x,y);
    printf("devited=%d\n",o);
    int p=multi(x,y);
    printf("multiplaction=%d\n",p);
}
int sum(int a,int b){//perameter
int sum=a+b;
return sum;
}
int sub(int a,int b){
int sub=(a-b);
return sub;
}
int div(int a,int b){
int div=a/b;
return div;
}
int multi(int a,int b){
int multi=a*b;
return multi;
}
