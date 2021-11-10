#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* back;

    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void enqueue(int x){
        
        Node* n = new Node(x);
        
        if(front == NULL){
            front=n;
            back=n;
            return;
        }

        back->next=n;
        back = n;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        Node* toDelete = front;
        front=front->next;
        delete toDelete;
        toDelete = NULL;
    }

    int peek(){
        if(front == NULL){
            cout<<"No element in Queue";
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL)
        return true;
        else
        return false;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();

    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.dequeue();
    }
    
    return 0;
}