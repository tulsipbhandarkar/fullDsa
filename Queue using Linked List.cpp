#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int val)
    {
        data=val;
        next=NULL;
    }
    
};

class queue
{
    node* front;
    node* back;
    public:
    queue()
    {
        front=NULL;
        back=NULL;
    }
    
    
    void enqueue(int x)
    {
        node* n= new node(x);
        
        if(back==NULL && front==NULL)
        {
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void dequeue()
    {
        if(back==NULL && front==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        
        delete todelete;
    }
        
    int peek()
    {
        if(back==NULL && front==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        
        return front->data;
        
    }
    
    bool empty()
    {
        if(front==NULL)
        return true;
        
        return false;
    }
    
};


int main(){


return 0;
	
	
}
