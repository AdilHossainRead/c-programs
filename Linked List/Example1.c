#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int data;
    struct ListNode* next;
};
ListNode* Head=NULL;
ListNode* Tail=NULL;
ListNode* creatNode(int Value)
{
   ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
   temp->data=value;
   temp->next=NULL;
}
void insert_value(value)
{
    if(Head==NULL)
    {
        head=creatNode(value);
        tail=head;
    }
    else
    {
        ListNode* temp=creatNode(value);
        Head->next=temp;
        Tail=Head->next;
    }
}
int main()
{
    insert_value(44);
}
