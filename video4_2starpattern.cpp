#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k,l;
    cin>>n;
    for ( i = 1; i<=n ;i++)
    {
       for ( j = n-i; j >=1; j--)
       {
           cout<<" ";
       }
       for (k = 1; k<=i; k++)
       {
           cout<<"*";
       }
       for (l=k-2; l >= 1; l--)
       {
           cout<<"*";
       }
       
       
       cout<<endl;
    }
    for ( i = n; i>=1 ;i--)
    {
       for ( j = n-i; j >=1; j--)
       {
           cout<<" ";
       }
       for (k = 1; k<=i; k++)
       {
           cout<<"*";
       }
       for (l=k-2; l >= 1; l--)
       {
           cout<<"*";
       }
       
       
       cout<<endl;
    }
    return 0;
}