#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,h=0;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
        h=max(a[i],h);
    }
    int b[h+1],min=INT_MAX;
    for (i = 0; i < h+1; i++)
    {
        b[i]=-1;
    }
    for (i = 0; i < n; i++)
    {
        if (b[a[i]]!=-1 && b[a[i]]<min)
        {
            min=b[a[i]];
        }
        b[a[i]]=i;
    }
    if (min==INT_MAX)
    {
        cout<<"No repeating integer";
    }
    else
    {
    cout<<"The smallest repeating integer is: "<<a[min];
    }
    return 0;
}