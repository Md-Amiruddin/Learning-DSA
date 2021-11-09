#include<bits/stdc++.h>
using namespace std;

int prec(char ch)  //returns precedence of operators
{
    if(ch=='^')
    return 3;
    else if(ch=='/' || ch=='*')
    return 2;
    else if(ch=='+' || ch=='-')
    return 1;
    else
    return -1;
}

string infixToPostfix(string s)
{
    string result="";
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
            result+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
            st.pop();
            }
        }
        else{
            while(!st.empty() && (prec(st.top()) >= prec(s[i]))){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string result="";
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){  //this is to reverse the brackets
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
        else{
            continue;
        }
    }

    // result=infixToPostfix(s);   <-- This can also be used instead of the snippet(lines 70-98).
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'  || s[i]>='0' && s[i]<='9'){
            result+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && (prec(st.top())) >= prec(s[i])){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}   

int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixToPostfix("5+7*(9+3)")<<endl;
    cout<<infixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}