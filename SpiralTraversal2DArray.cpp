#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int a[n][m];
    for ( i = 0; i < n; i++)
    {
        for (j = 0;j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    
    int row_start=0, row_end=n-1, col_start=0, col_end=m-1, row=0, col=0,count=0;
    while (row_start<=row_end && col_start<=col_end)
    {
        //1st row
        if(count<n*m){
        for (col = col_start; col <=col_end; col++)
        {
            cout<<a[row_start][col]<<" ";
            count++;
        }
        row_start++;
        }
        //last col
        if(count<n*m){
        for ( row = row_start; row<=row_end; row++)
        {
            cout<<a[row][col_end]<<" ";
            count++;
        }
        col_end--;
        }
        //last row
        if(count<n*m){
        for (col = col_end; col >=col_start; col--)
        {
            cout<<a[row_end][col]<<" ";
            count++;
        }
        row_end--;
        }

        //1st col
        if(count<n*m){
        for ( row = row_end; row>=row_start; row--)
        {
            cout<<a[row][col_start]<<" ";
            count++;
        }
        col_start++;
        }
    }    
    return 0;
}