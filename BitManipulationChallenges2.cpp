#include<bits/stdc++.h>
using namespace std;
int unique(int a[],int len)
{
    int xorsum=0;
    for (int i = 0; i < len; i++)
    {
        xorsum^=a[i];
    }
    return(xorsum);
}

void unique2(int a[],int len)
{
    int xorsum=0;
    for (int i = 0; i < len; i++)
    {
        xorsum^=a[i];
    }

    int getBit=0,pos=0;
    while (getBit!=1 && pos<4)
    {
        if(xorsum & (1<<pos))        //getbit function
        {
        getBit=1;
        break;
        }
        pos++;
    }
    
    int newxor=0;
    for (int i = 0; i < len; i++)
    {
        if(a[i] & (1<<pos))         //getbit function
        newxor^=a[i];
    }
    
    cout<<newxor<<endl;
    cout<<(xorsum^newxor);
}

int unique3(int a[], int len)
{
    int result=0;
    for (int i = 0; i < 64; i++)
    {
        int sum=0;
        for (int j = 0; j < len; j++)
        {
            if(a[j] & (1<<i))         //getbit function
            sum++;
        }
        if (sum%3!=0)
        {
            result=result | (1<<i);    //setbit function
        }
    }
    return(result);
}

int main()
{
    int a[]={1,2,3,4,1,2,3,1,2,3};
    // cout<<unique(a,7);
    //unique2(a,8);
    cout<<unique3(a,10);
    return 0;
}