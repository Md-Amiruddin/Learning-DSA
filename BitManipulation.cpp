#include<iostream>
using namespace std;

bool getBit(int n,int pos)
{
    return(n & (1<<pos));
}

int setBit(int n, int pos)
{
    return(n | (1<<pos));
}

int clearBit(int n, int pos)
{
    return( n & ~(1<<pos));
}

int updateBit(int n, int pos, int value)
{
    n=clearBit(n,pos);
    return(n | (value<<pos));
}

int main()
{
    int v=5;
    cout<<getBit(v,1)<<endl;
    v=setBit(v,1);
    cout<<getBit(v,1)<<endl;
    v=clearBit(v,1);
    cout<<getBit(v,1)<<endl;
    v=updateBit(v,1,1);
    cout<<getBit(v,1)<<endl;
    return 0;
}