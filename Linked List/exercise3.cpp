
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int data;
    ListNode* next;
};
//typedef struct ListNode* ListNode;
ListNode* Head=NULL;
ListNode* Tail=NULL;

ListNode* creatNode(int value)
{
    ListNode* Temp=(ListNode*)malloc(sizeof(ListNode));
    Temp->data=value;
    Temp->next=NULL;
    return Temp;
}
void insert_value(int value)
{
    if(Head==NULL)
    {
        Head=creatNode(value);
        Tail=Head;
    }
    else
    {
        ListNode* Temp=creatNode(value);
        Tail->next=Temp;
        Tail=Tail->next;
        //Tail=Temp;
    }
}
void printf_listnode(ListNode* Head)
{
    printf("Print listnode using for loop:");
    for(ListNode* i=Head;i!=NULL;i=i->next)
    {
        printf(" %d",i->data);
    }
    printf("\n");
}
void insert_first_value(int value)
{
    ListNode* Temp=creatNode(value);
    Temp->next=Head;
    Head=Temp;

}
ListNode* linear_search(int key)
{
    for(ListNode* i=Head;i!=NULL;i=i->next)
    {
        if(i->data==key)
        {
            {
                return i;
            }
        }
    }
    return NULL;
}
void insert_after(int data,int key)
{
    ListNode* location=linear_search(key);
    if(location==NULL)
    {
        return;
    }
    else
    {
        ListNode* Temp=creatNode(data);
        Temp->next=location->next;
        location->next=Temp;


    }
}
void insert_befor(int data,int key)
{
    ListNode* location=linear_search(key);
    if(location==NULL)
        return;
    else if(location==Head)
    {
        Temp->next=Head;
        Head=temp;
    }
    else
    {
        ListNode* temp=creatNode(data);
        temp->next=location;

    }
}
int main()
{
    insert_value(44);
    insert_value(43);
    insert_value(42);
    printf_listnode(Head);
    insert_first_value(55);
    printf_listnode(Head);
    ListNode* p=linear_search(44);
    if(p==NULL)
        printf("data is not found");
    else
         printf("data is founded");
    insert_after(46,44);
    printf_listnode(Head);
    insert_befor(88,42);
}
