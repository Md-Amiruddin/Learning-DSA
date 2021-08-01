#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s,st=0,en=-1,x=0;
    cin>>n>>s;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    while (!(x>s))
    {
        en++;
        x+=a[en];
        if (x==s)
        {
        cout<<"start: "<<st+1<<" end: "<<en+1;
        return 0;    
        }
    }
    while (st!=en)
    {
        x-=a[st];
        st++;
        if(x==s)
        {
        cout<<"start: "<<st+1<<" end: "<<en+1;
        return 0;
        }
    }
    cout<<"Such a sub-array doesn not exist";
    return 0;
}