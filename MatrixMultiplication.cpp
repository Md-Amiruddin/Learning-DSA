#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n1,m1,n2,m2;
    cin>>n1>>m1;
    cin>>n2>>m2;

    //checking prerequisites
    if (m1!=n2)
    {
        cout<<"Multiplication not possible";
        return 0;
    }

    //1st Array Input
    cout<<"Input 1st array:"<<endl;
    int a[n1][m1];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            cin>>a[i][j];
        }
    }

    //2nd Array Input
    cout<<"Input 2nd array:"<<endl;
    int b[n2][m2];
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
        {
            cin>>b[i][j];
        }
    }

    //declaring and initializing array to store result
    int c[n1][m2];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            c[i][j]=0;
        }
    }
    
    //Multiplying
    for (i = 0; i < n1 ; i++)
    {
        for (j=0; j < m2; j++)
        {
            for  (k = 0; k < m1; k++)
            {
            c[i][j]+=(a[i][k]*b[k][j]);   
            }
        }
    }
    
    //Printing result
    cout<<"Result of Multiplication:"<<endl;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}