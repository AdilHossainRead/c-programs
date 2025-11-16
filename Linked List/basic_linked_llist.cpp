#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int data;
    struct ListNode* next;
};
typedef struct ListNode ListNode;//for c++
int main()
{
    ListNode* block1=(ListNode*)malloc(sizeof(ListNode));
    block1->data=5;
    block1->next=NULL;

    ListNode* block2=(ListNode*)malloc(sizeof(ListNode));
    block2->data=7;
    block2->next=NULL;

    ListNode* block3=(ListNode*)malloc(sizeof(ListNode));
    block3->data=8;
    block3->next=NULL;

    ListNode* block4=(ListNode*)malloc(sizeof(ListNode));
    block4->data=10;
    block4->next=NULL;

    printf(" %d",block1->data);
    printf(" %d",block2->data);
    printf(" %d",block3->data);
    printf(" %d",block4->data);


    printf("\nAfter connected block: \n");
    block1->next=block2;
    block2->next=block3;
    block3->next=block4;
    printf(" %d",block1->next->data);
    printf(" %d",block1->next->next->data);
    printf(" %d",block1->next->next->next->data);

    printf("\n printf using loop:");
    ListNode* head=block1;
    ListNode* tell=head;
    while(tell!=NULL)
    {
        printf(" %d",tell->data);
        tell=tell->next;
    }



}
