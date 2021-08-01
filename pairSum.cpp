#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,y,curr=0,j;
    cin>>n>>y;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (i = 1; i < n; i++)
    {
        curr=a[i];
        j=i-1;
        while (a[j]>curr && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=curr;
    }
    int st=0,en=n-1;
    while(st!=en)
    {
        if (a[st]+a[en]==y)
        {
            cout<<"Pair Sum exists";
            return 0;
        }
        if (a[st]+a[en]>y)
        {
            en--;
        }
        if (a[st]+a[en]<y)
        {
            st++;
        }
    }
    cout<<"Pair Sum does not exist";
    return 0;
}