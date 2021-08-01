#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str="632189743";
    sort(str.begin(),str.end(),greater<int>());
    string s1="abcFed";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<str<<endl;
    cout<<s1;
    return 0;
}