/*5. Write a program (WAP) that will take two numbers X and Y as inputs. Then it will print
the square of X and increment (if X<Y) or decrement (if X>Y) X by 1, until X reaches Y. If
and when X is equal to Y, the program prints “Reached!”
Sample input(X,Y)
10 5 Sample output 100, 81, 64, 49, 36, Reached!
5 10 Sample output 25, 36, 49, 64, 81, Reached!
10 10 Reached!Adil*/
#include<stdio.h>
int main()
{
    int i,x,y,num;
    printf("Enter x=");
    scanf("%d",&x);
    printf("Enter y=");
    scanf("%d",&y);
    if(x>y)
    {
        for(i=x; i>=y; i--)
        {
            if(i==y)
            {
                printf("Reached!");
            }
            else
            {
                num=i*i;
                printf("%d,",num);
            }

        }

    }
    else if(x<y)
    {
        for(i=x; i<=y; i++)
        {
            if(i==y)
            {
                printf("Reached!");
            }
            else
            {
                num=i*i;
                printf("%d,",num);
            }

        }
    }
    else if (x==y)
    {
        printf("Reched!");
    }
}
