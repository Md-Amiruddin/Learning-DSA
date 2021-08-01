#include<bits/stdc++.h>
//#include<C:\Users\Md Amiruddin\Desktop\c++ codes\fibonacci func.cpp>
using namespace std;
int main()
{
    int i,n,y=0,x=0;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Sum of Sub Arrays:"<<endl;
    for (i = 0; i < n; i++)
    {
        for (int j = i; j <n; j++)
        {
            x+=a[j];
            cout<<x<<" ";
        }
        x=0;
        }
    //not part of program, just tried using function from another program
    //cout<<endl<<fact(5);
    return 0;
}