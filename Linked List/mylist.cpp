#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class mylist
{
    private:
    Node *head;
    Node *tail;
    public:
    mylist()
    {
        head=NULL;
        tail=NULL;
    }
    void addFirst(int data)
    {
        Node *temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    void addLast(int data)
    {
        if(head==NULL){
            addFirst(data);
        }
        else{
            Node *temp=new Node(data);
            tail->next=temp;
            tail=temp;
        }
    }
    void add(int data)
    {
        addLast(data);
    }
    void addMid(int data)
    {
        Node *temp=head;
        int counter=0;
        while(temp!=NULL){
            counter++;
            temp=temp->next;
        }
        counter=counter/2;
        int i=0;
        temp=head;
        Node *prev;
        while(i<counter)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        Node *x=new Node(data);
        prev->next=x;
        x->next=temp;
    }
    void display()
    {
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    mylist li;
    li.add(10);
    li.addLast(20);
    li.addFirst(5);
    li.add(30);
    li.addMid(15);
    li.display();
}
