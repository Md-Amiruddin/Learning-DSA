#include<iostream>
using namespace std;
int fact(int n){
    if(n<=0)
    return 1;
    int f=1;
    while (n>0)
    {
        f*=n;
        n--;
    }
    return f;
}
/*int main()
{
    int n,x,i,z;
    cout<<fact(2)/(fact(2)*fact(0));
    cin>>n;
    x=n;
    for (int j = 0; j <=x; j++)
    {
        if(j==1){
        n--;
            continue;
        }
        for (i = n; i >0; i--){
        cout<<" ";
        }
        n--;
        for (z = 0; z <=j; z++)
        {
            cout<<(fact(j)/(fact(j-z)*fact(z)))<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/