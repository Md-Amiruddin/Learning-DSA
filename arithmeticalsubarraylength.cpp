#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,u=0,i,y,h=0;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (i = 1; i < n-1; i++)
    {
        x=a[i]-a[i-1];
        y=a[i+1]-a[i];
        if (y==x)
        {
            u+=1;
        }
        else
        {
            h=max(h,u);
            u=0;
        }
    }
    cout<<"Largest arithmetical sub-array:"<<(max(h,u)+2);
    return 0;
}