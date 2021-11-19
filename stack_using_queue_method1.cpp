#include<bits/stdc++.h>
using namespace std;

//Implementation of stack using queue where POP operation is costly.

class Stack{
    queue<int> q1;
    queue<int> q2;

    public:

    void push(int val){
        q1.push(val);
    }

    void pop(){

        if(q1.empty()){
            cout<<"Stack underflow\n";
            return;
        }

        while(q1.size()!=1){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        q1.pop();
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }

    int top(){

        if(q1.empty()){
            cout<<"No elements in Stack\n";
            return -1;
        }
        
        int x;

        while(!q1.empty()){
            x = q1.front();
            q1.pop();
            q2.push(x);
        }

        queue<int> temp = q1;
        q1=q2;
        q2=temp;
        return x;
    }

    bool empty(){
        if(q1.empty())
        return true;
        else
        return false;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<"\n";

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<s.top()<<"\n";

    return 0;
}