#include<bits/stdc++.h>
using namespace std;

int power(int num,int pow, int ans){
    static int x=1;
    cout<<x++;        //prints number of times the power function is called
    
    if(pow==1){
        return num;
    }
    if(pow==0){
        return 1;
    }

    int calculate_power = power(num,pow/2,ans);
    if(pow%2==0)
    // return  power(num,pow/2,ans) * power(num,pow/2,ans);                // code in comment is from didi of recursion one shot, didn't use it because i thought it uses more memory than my code
    ans=calculate_power*calculate_power;
    else
    // return  power(num,pow/2,ans) *  power(num,pow/2,ans) * num;
    ans=calculate_power*calculate_power*num;

    return ans;
}

int main()
{
    int n=2;
    int pow=10;
    int n_pow=power(n,pow,0);
    cout<<" "<<n_pow;
    return 0;
}