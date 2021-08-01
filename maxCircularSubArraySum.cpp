#include<bits/stdc++.h>
using namespace std;
int kadane(int a[], int n)
{
    int currsum=0, mxsum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum+=a[i];
        if (currsum<0)
        {
            currsum=0;
        }
        mxsum=max(currsum,mxsum);
    }
    return mxsum;
}

int main()
{
    int n,i,totalsum=0;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
        totalsum+=a[i];
    }
    int wrapsum, nonwrapsum=kadane(a,n);
    for (i = 0; i < n; i++)
    {
        a[i]=-a[i];
    }
    wrapsum=totalsum + kadane(a,n);
    cout<<"Maximum Circular Sub Array Sum= "<<max(wrapsum,nonwrapsum);
    return 0;
}