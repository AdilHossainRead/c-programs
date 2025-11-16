#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int data;
    struct ListNode* next;
};
typedef struct ListNode ListNode;
ListNode* head=NULL;
ListNode* tail=NULL;

ListNode* creatNode(int value)
{
    ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
    temp->data=value;
    temp->next=NULL;
    return temp;
}

insert_value(int value)
{
    if(head=NULL)
    {
        head=creatNode(value);
        tail=head;
    }else
    {
        ListNode* temp=creatNode(value);
        tail->next=temp;
        tail=tail->next;
        //tail=temp;
    }
}

int main()
{
    insert_value(24);
}
