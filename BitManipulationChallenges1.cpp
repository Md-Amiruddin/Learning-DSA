#include<iostream>
using namespace std;

bool ispowerof2(int n)
{
    return(n && !(n & (n-1)));
}

int numberofones(int n)
{
    int i=0;
    while (n!=0)
    {
        n=n & (n-1);
        i++;
    }
    return i;
}

void subsets(int n[],int len)
{
    for (int i = 0; i < (1<<len); i++)    //(1<<len) is same as 2^len
    {
        for (int j = 0; j < len; j++)
        {
            if (i & (1<<j))              //getBit operation in if statement
            {
                cout<<n[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Is "<<n<<" power of 2? "<<((ispowerof2(n))?"true":"false")<<endl;
    cout<<"Number of 1 in it's binary= "<<numberofones(n)<<endl;
    cout<<"Subsets of the array are:\n";
    subsets(a,n);
    return 0;
}