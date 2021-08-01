#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx=INT_MIN,miin=INT_MAX,i,index=0;
    cin>>n;
    int a[n],b[n];
    for (i = 0 ; i < n ; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for (i = 0; i < n; i++)
    {
        b[i]=mx-a[i];
        if ((b[i]<miin)&&(b[i]!=0))
        {
            miin=b[i];
            index=i;
        }
    }
    cout<<"2nd Largest element of Array: "<<a[index];
    return 0;
}