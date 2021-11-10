#include<bits/stdc++.h>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;
    
    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x){
        if(back == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }

        ++back;
        arr[back]=x;

        if(front == -1)
        front++;
    }

    void dequeue(){
        if(front==-1 || front>back){
            cout<<"Queue empty"<<endl;
            return;
        }
        
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"Queue empty"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back)
        return true;
        else
        return false;
    }
};

int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // q.dequeue();
    // q.dequeue();

    // q.enqueue(9);

    // cout<<q.peek()<<endl;
    // cout<<q.empty()<<endl;

    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.dequeue();
    }
    
    return 0;
}