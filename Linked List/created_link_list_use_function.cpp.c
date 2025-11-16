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
        //tail=temp;
    }
}

void print_list(ListNode* head)
{
      printf("The elements of the list are: ");
    for(ListNode* i=head; i!=NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
     printf("print The elements using while loop of the list are: ");
    while(head!=NULL)
    {
        printf(" %d",head->data);
        head=head->next;
    }
}
int main()
{
    insert_value(10);
    insert_value(20);
    insert_value(30);
    insert_value(40);
    insert_value(50);
    insert_value(60);
    print_list(head);
}

