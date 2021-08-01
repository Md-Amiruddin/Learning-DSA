#include<bits/stdc++.h>
using namespace std;

int Sum(int n){
    
    if(n==0)
    return 0;

    int prevSum = Sum ( n - 1 );
    return ( n + prevSum );
}

int cnt=0;          
int z=0;             //global variables
int powertype1(int n){
    if(cnt==z)
    return 1;
    cnt++;
    return(n * powertype1(n));
}

int powertype2(int n, int p){
    if(p==0)
    return 1;

    int prevPower= powertype2(n, p-1);
    return (n* prevPower);
}

int factorial(int n){
    if(n==0)
    return 1;

    return(n * factorial(n-1));
}

long long fib(long long pos){
    if(pos == 0 ||pos == 1 )
    return pos;

    return fib(pos-1)+fib(pos-2);
}

int main(){
    //int p;
    long long n;
    cin>>n;
    //cin>>p;
    //cout<<Sum(n);
    //cout<<powertype1(n);
    //cout<<powertype2(n,p);
    //cout<<factorial(n);
    cout<<fib(n);
}