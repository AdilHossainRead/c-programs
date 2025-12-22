
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node* next;
};
node* font=NULL;
node* rear=NULL;
void enqueue(int value)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    if(rear==NULL)
    {
        font=rear=newNode;
        rear->next=font;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
        rear->next=font;
    }
    printf("%d enQueue\n",value);
}
void dequeue()
{
    if(font==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        node* temp=font;
        printf("%d dequeue",temp->data);
        font=font->next;
        free(temp);
        if(font==NULL)
        {
            font=rear=NULL;
        }else if(font==rear)
        {
            font = NULL;
        rear = NULL;
        }
        else {
        font = font->next;
        rear->next = font;
    }
    }
}
int main()
{
    enqueue(11);
    enqueue(22);
    enqueue(32);
    enqueue(23);
    enqueue(44);
    dequeue();
    dequeue();
}
