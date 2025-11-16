#include<stdio.h>
#include<stdlib.h>
struct LinkNode
{
    int data;
    struct LinkNode* next;
};
typedef struct LinkNode LinkNode;
LinkNode* head=NULL;
LinkNode* tail=NULL;

LinkNode* creatNode(int value)
{
    LinkNode* temp= (LinkNode*)malloc(sizeof(LinkNode));
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
        LinkNode* temp=creatNode(value);
        tail->next=temp;
        tail=tail->next;
    }
}

print_list()
{
    printf("The elements of the list are: ");
    for(LinkNode* i=head; i!=NULL; i=i->next)
    {
        printf(" %d",i->data);
    }
    printf("\n");
    /*printf("print The elements using while loop of the list are: ");
    while(head!=NULL)
    {
        printf(" %d",head->data);
        head=head->next;
    }*/
}

LinkNode* lineat_searching(int key)
{
    for(LinkNode* i=head;i!=NULL;i=i->next)
    {
        if(i->data==key)
        {
            return i;
        }
    }
    return NULL;
}

void insert_after(int data,int key)
{

}
int main()
{
    insert_value(10);
    insert_value(101);
    insert_value(20);
    insert_value(202);
    insert_value(30);
    insert_value(303);
    insert_value(40);
    print_list();
}
