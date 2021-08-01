#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    int a[n][n];

    //taking input
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }

    //transposing
    for ( i = 0; i < n; i++)
    {
        for ( j = i; j < n; j++)
        {
            k=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=k;
        }
        
    }

    //printing
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}