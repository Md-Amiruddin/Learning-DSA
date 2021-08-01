#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int b[n],currsum=0,maxsum=INT_MIN;
    for (i = 0; i < n; i++)
    {
        currsum+=a[i];
        maxsum=max(maxsum,currsum);
        if (currsum<0)
        currsum=0;
    }
    cout<<"Max sub-array sum: "<<maxsum;
}