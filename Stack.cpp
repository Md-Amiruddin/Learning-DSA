#include<bits/stdc++.h>
using namespace std;

#define n 3

class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"No element to pop\n";
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No element in the Stack\n";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<< st.Top()<< "\n";
    st.pop();
    cout<< st.Top() <<"\n";
    cout<< st.empty() <<"\n";
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<< st.empty()<<"\n";
    st.Top();
    st.pop();
    return 0;
}