#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k,mx=INT_MIN,z=0;
    cin>>n;
    int a[n];
    cout<<"Enter values into the Array:"<<endl;
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
        mx=max(abs(a[i]),mx);
    }
    cout<<"Enter the rank of the element to be searched: ";
    cin>>k;
    if ((k>n)||(k<1))
    {
        cout<<"Such an element does not exist";
        return 0;
    }
    bool pt[mx+1],nt[mx+1];
    for (i = 0; i < mx+1; i++)
    {
        pt[i]=false;
        nt[i]=false;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i]>=0)
        {
            pt[a[i]]=true;
        }
        else
        {
            nt[abs(a[i])]=true;
        }
    }
    cout<<"The "<<k<<"th largest element of the array is: ";
    i=mx+1;
    while (i>=0)
    {
        if (pt[i]==true)
        {
            z++;
            if (z==k)
            {
                cout<<i;
                return 0;
            }
            
        }
        i--;
    }
    i=0;
    while (i<mx+1)
    {
        if (nt[i]==true)
        {
            z++;
            if (z==k)
            {
                cout<<"-"<<i;
                return 0;
            }
        }
        i++;
    }
    cout<<"Some Error occured!";
    return 0;
}