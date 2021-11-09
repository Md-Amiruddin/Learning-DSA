#include <bits/stdc++.h>
using namespace std;

bool balancedParenthesis(string s)
{
    stack<char> st;
    int quote_checker = 0;
    for (char i : s)
    {

        if (i == '(' || i == '{' || i == '[' || i=='<')
        {
            st.push(i);
        }

        else if (i == ')' || i == '}' || i == ']' || i=='>')
        {
            switch (i)
            {
            case ')':
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                break;

            case '}':
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                break;

            case ']':
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                break;

            case '>':
                if (!st.empty() && st.top() == '<')
                {
                    st.pop();
                    continue;
                }
                break;
            }
            return false;
        }

        else{
            continue;
        }
    }

    if(!st.empty())
    return false;

    return true;
}

int main()
{
    cout << balancedParenthesis("[{()}]")<<endl;
    cout<< balancedParenthesis("[{([)}]")<<endl;
    cout << balancedParenthesis("]")<<endl;
    return 0;
}