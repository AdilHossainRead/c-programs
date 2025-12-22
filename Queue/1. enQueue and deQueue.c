#include<stdio.h>
#define max 10
int queue[max];
int font=-1;
int rear=-1;
void EnQueue(int value)
{
   if(rear==max-1)
   {
       printf("Queue overflow\n");
   }
   else
   {
       if(font==-1)
       {
           font=0;
       }
       rear++;
       queue[rear]=value;
       printf("%d add in queue\n",value);
   }
}
void DeQueue()
{
    if(font==-1 || font>rear)
    {
        printf("stack underflow");
    }
    else
    {
        printf("%d value deleted\n",queue[font]);
        font++;
        if(font>rear)
        {
            font=rear=-1;
            //reser queue.
        }
    }
}
int main()
{
    EnQueue(10);
    EnQueue(23);
    EnQueue(32);
    EnQueue(24);
    DeQueue();
    DeQueue();

}
