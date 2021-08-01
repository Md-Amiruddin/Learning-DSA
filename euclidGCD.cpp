#include<iostream>
using namespace std;
int main()
{
    /**
    GCD(HCF) using Euclid Algorithm
    */

    int a;
    int b,rem;
    cin>>a>>b;
    cout<<"GCD(HCF) of "<<a<<" and "<<b<<" is : ";
    while (b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }
    cout<<a;
}