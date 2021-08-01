#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k;
    cin>>n>>m;
    int a[n][m];
    cout<<"Enter the no to be searched:"<<endl;
    cin>>k;

    //taking array input
    cout<<"Enter the sorted 2D array:"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }

    //searching
    i=n,j=0;
    while ((i>=0 && i<=n)&&(j>=0 && j<=m))
    {
        if (a[i][j]==k)
        {
            cout<<"Found!";
            return 0;
        }
        if(k>a[i][j])
        j++;
        if(k<a[i][j])
        i--;
    }
    cout<<"not Found";
    return 0;
}