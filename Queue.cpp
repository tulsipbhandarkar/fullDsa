#include"iostream"
using namespace std;
#define n 100
class queue{
    int* arr;
    int front;
    int back;
    
    public:
    queue()
    {
        arr=new int[n];
        front=-1;
        back=-1;
    }
    
    void enqueue(int x)
    {
        if(front==-1 && back==-1)
        {
            front++;
            back++;
            arr[back]=x;
            return;
        }
        if(back==n-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        back++;
        arr[back]=x;
    }
    
    void dequeue()
    {
        if(front==-1 ||front>back)
        {
         cout<<"The queue is empty"<<endl;
         return;
        }
        front++;
    }
    
    int peek()
    {
        if(front==-1 ||front>back)
        {
         cout<<"The queue is empty"<<endl;
         return -1;
        }
        return arr[front];
    }
    
    bool isempty()
    {
        if(front==-1 ||front>back)
        {
        return true;
        }
        
        return false;
    }
};
int main()
{
    
    queue qt;
    qt.enqueue(5);
    
    qt.enqueue(3);
    
    qt.enqueue(2);
    
    qt.enqueue(1);
    cout<<qt.peek()<<endl;
    
    qt.dequeue();
    cout<<qt.peek()<<endl;
    return 0;
    
}