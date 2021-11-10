#include<bits/stdc++.h>
using namespace std;

class Queue{                             //Implementation of queue using stack method 1
    stack<int> s1;
    stack<int> s2;
    
    public:
    
    void enqueue(int val){
        s1.push(val);
    }

    int dequeue(){
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue underflow"<<endl;
            return -1;
        }

        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        }

        int topval=s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.empty() && s2.empty())
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

    cout<<q.dequeue()<<endl;

    q.enqueue(88);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}