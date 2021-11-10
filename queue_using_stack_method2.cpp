#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> st;

    public:

    void enqueue(int val){
        st.push(val);
    }

    int dequeue(){
        if(st.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x=st.top();
        st.pop();
        if(st.empty()){
            return x;
        }
        int item = dequeue();
        st.push(x);
        return item;
    }

    bool empty(){
        if(st.empty())
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
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}