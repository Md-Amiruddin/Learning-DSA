#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str="632189743";
    sort(str.begin(),str.end(),greater<int>()); //to sort the string
    string s1="abcFed";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper); //to transform to upper case
    cout<<str<<endl;
    cout<<s1<<endl;

    //to find length of string
    cout<<s1.size()<<endl;

    //to take input of string with multiple words separated by spaces
    string l;
    getline(cin,l);
    cout<<l<<endl;

    //to add characters to the end of string, use this method for minimal time complexity
    l.push_back('h');
    cout<<"After Pushback: "<<l<<endl;

    //reverse string
    string rev_l=l;
    reverse(rev_l.begin(),rev_l.end());
    cout<<rev_l<<endl;

    return 0;
}