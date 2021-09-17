#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node(int value)
    {
        data=value;
        next=NULL;
    }
    
};

/*
class node{
    public:
    int data;
    node* next;
    node* previous;
    node(int val)
    {
        data=val;
        next=NULL;
        previous=NULL;
        
    }
}
*/                              //doubly



void insertatTail(node* &head,int val)
{
    node* n=new node(val);

if(head==NULL)
{
     head=n;
     return;
}
    node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}




void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
        
    }
    cout<<"NULL"<<endl;
}




void insertathead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}





bool find(node* &head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return true;
        
        temp=temp->next;
    }
    return false;
}



void deleteatHead(node* &head)
{
    node* temp=head;
    head=temp->next;
    
    delete temp;
}




void deleteion(node* &head,int val)
{
    if(head==NULL)
    return;
    
    if(head->next==NULL)
{
   deleteatHead(head);
    return;
}

    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    
    temp->next=temp->next->next;
    delete todelete;
}


node* reverselinkedList(node* &head)
{
    node* previousptr=NULL;
    node* currentptr=head;
    node* nextptr;
    
    while(currentptr!=NULL)
    {
        nextptr=currentptr->next;
        
        currentptr->next=previousptr;
        
        previousptr=currentptr;
        currentptr=nextptr;
        
        
    }
    return previousptr;
    
}




int main()
{
    
    node * head;
    head=NULL;
    insertatTail(head,1);

    insertatTail(head,2);

    insertatTail(head,3);

    insertatTail(head,4);

    insertatTail(head,5);

    insertatTail(head,6);

    display(head);

    node* newhead=reverselinkedList(head);

    display(newhead);
    
    return 0;
    
}