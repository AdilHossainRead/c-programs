#include<stdio.h>
#include<stdlib.h>
struct listnode
{
    int data;
    struct listnode* next;
};

listnode* head=NULL;
listnode* tail=NULL;

listnode* creatNode(int value)
{
    listnode* temp=(listnode*)malloc(sizeof(listnode));
    temp->data=value;
    temp->next=NULL;
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
       listnode* temp=creatNode(value);
       tail->next=temp;
       tail=tail->next;
    }
}

void printf_listnode(listnode* head)
{
    printf("Print listnode using for loop:");
        for(listnode* i=head;i!=NULL;i=i->next)
        {
            printf(" %d",i->data);
        }
    printf("\nPrint listnode using while loop:");
    while(head!=NULL)
    {
        printf(" %d",head->data);
        head=head->next;
    }printf("\n");
}
void insert_first(int value)
{
    if(head==NULL)
    {
        head=creatNode(value);
        tail=head;
    }
    else
    {
        listnode* temp=creatNode(value);
        temp->next=head;
        head=temp;
    }
}
listnode* linear_search(int key)
{
    for(listnode* i=head;i!=NULL;i=i->next)
    {
       if(i->data==key)
       {
           return i;
       }
    }
    return NULL;
    /*while(head!=NULL)
    {
        if(head==key)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;*/
}
void insert_after(int data, int key)
{
    listnode* loc=linear_search(key);
    if(loc==NULL)
       return;

    listnode* temp=creatNode(data);
    temp->next=loc->next;
    loc->next=temp;

}
void delete_first(int data)
{
    if(head==NULL);
    return;

    {
        listnode*temp=head;
        head=head->next;
        if(head==NULL)
        {
            tail=head;
        }
    }
}
void delete_last()
{
    if(head=NULL)
        return;
    else if(head=tail)
    {
        free(head);
        tail=head=NULL;
    }else
    {
        listnode* second_last=head;
        while(second_last->next->next!=NULL)
        {
            second_last->next;
        }
        free(tail);
        second_last->next=NULL;
        tail=second_last;
    }
}
int main()
{
    insert_value(10);
    insert_value(20);
    insert_value(30);
    insert_value(40);
    insert_value(50);
    printf_listnode(head);
    insert_first(12);
    insert_first(22);
    insert_after(44,40);
    printf_listnode(head);
    delete_last();
    printf_listnode(head);


}
