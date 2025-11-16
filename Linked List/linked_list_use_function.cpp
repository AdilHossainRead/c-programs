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

void insert_value(int value)
{
    if(head==NULL)
    {
        head=creatNode(value);
        tail=head;
    }
    else
    {
        ListNode* temp=creatNode(value);
        tail->next=temp;
        tail=tail->next;
    }
}

void printfList()
{
    printf("the elements of the list are: ");
    while(tail->next!=NULL)
    {
        printf("%d",tail->data);
    }
}
int main()
{
    insert_value(10);
    insert_value(20);
    printfList();

}
