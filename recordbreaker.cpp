#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,max=0,r=0,i;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for ( i = 0; i < n; i++)
    {
        if (a[i]>max)
        {
            if (i==n-1)
            {
                r+=1;
                break;
            }
            if (a[i+1]<a[i])
            {
                r+=1;
            }
            max=a[i];
        }
    }
    cout<<"No of record breaking days: "<<r;
    return 0;
}