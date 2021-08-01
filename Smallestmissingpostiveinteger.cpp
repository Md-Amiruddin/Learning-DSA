#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,mx=INT_MIN;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    bool b[mx+1];
    for (i = 0; i < mx+1; i++)
    {
        b[i]=false;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i]>-1)
        {
            b[a[i]]=true;
        }        
    }
    for (i = 0; i < mx+1; i++)
    {
        if(b[i]==false)
        break;
    }
    cout<<"Smallest missing postive integer: "<<i;
    return 0;
}