#include<bits/stdc++.h>
using namespace std;

int tilingWays(int n)
{
    if(n==0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    return tilingWays(n-1) + tilingWays(n-2);
}

int friendsPairing(int n)
{
    if(n==0 || n==1 || n==2){
        return n;
    }

    return friendsPairing(n-1) + (friendsPairing(n-2)*(n-1));
}

int wt[3]={10,20,30};
int val[3]={100,50,150};

int knapsack(int weightCapacity,int value)
{
    int maxvalue=0;
    int maxIndex=0;
    for(int i=0;i<3;i++){
        if(val[i]>maxvalue){
        maxvalue=val[i];
        maxIndex=i;
        }
    }
    val[maxIndex]=0;
    int newweightCapacity=weightCapacity-wt[maxIndex];
    int newvalue=value+maxvalue;
    if(newweightCapacity<0){
        return value;
    }
    if(newweightCapacity==0){
        return newvalue;
    }

    return knapsack(newweightCapacity,newvalue);
}

int main()
{
    // cout<<tilingWays(4);
    // cout<<friendsPairing(4);
    cout<<knapsack(50,0);
    return 0;
}