#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if(st.empty()){
        st.push(x);
    }else{
        int ele = st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(ele);
    }
}

void reverseStack(stack<int> &st)
{
    if(st.size()<=1){
        return;
    }
    int ele=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}

int main()
{
    stack<int> st;
    st.push(2);  //bottommost stack
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);  //topmost stack
    reverseStack(st);
    cout<<"Reversed Stack:\n";
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}