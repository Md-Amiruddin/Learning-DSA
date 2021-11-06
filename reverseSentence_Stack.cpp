#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    string word = "";
    for(int i = 0; i<s.size();i++)
    {
        if(s[i]==' '){
            st.push(word);
            word="";
        }
        else if(i==s.size()-1){
            word = word + s[i];
            st.push(word);
            word=" ";
        }
        else{
            word = word + s[i];
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    
    string s;
    cout<<"Enter a Sentence: ";
    getline(cin,s);
    reverseSentence(s);
    
    return 0;
}