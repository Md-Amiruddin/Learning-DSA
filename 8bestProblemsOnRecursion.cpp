#include<iostream>
#include<string>
using namespace std;

string keypad[10]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypadProb(string digits,string ans){
    if(digits.length()==0){
    cout<<ans<<endl;
    return;
    }

    string keys=keypad[digits[0]-'0'];
    
    for (int i = 0; i < keys.length(); i++)
    {
        keypadProb(digits.substr(1),ans+keys[i]);        
    }
}

void asciisubseq(string s, string z)
{
    if(s.length()==0){
    cout<<z<<endl;
    return;
    }

    char ch=s[0];
    string restOfString=s.substr(1);

    asciisubseq(restOfString,z);
    asciisubseq(restOfString,z+ch);
    asciisubseq(restOfString,z+to_string((int)ch));
}

void subseq(string s, string z)
{
    if(s.length()==0){
    cout<<z<<endl;
    return;
    }

    char ch=s[0];
    string restOfString=s.substr(1);

    subseq(restOfString,z);
    subseq(restOfString,z+ch);
}

string moveX(string s)
{
    if(s.length()==0)
    return "";

    char ch=s[0];
    string ans = moveX(s.substr(1));

    if(ch=='x')
    return (ans+ch);

    return ch+ans;
}

string removeDuplicate(string s)
{
    if(s.length()==0)
    return "";

    char ch=s[0];
    string ans = removeDuplicate(s.substr(1));
    if(ans[0]==ch)
    {
        return ans;
    }
    return(ch+ans);
}

void towerOfHanoi(int n,char src, char helper, char dest)
{
    if(n==0)
    return;

    towerOfHanoi(n-1,src,dest,helper);
    cout<<"Move a loop from "<<src<<" to "<<dest<<"\n";
    towerOfHanoi(n-1,helper,src,dest);
}

void reverse(string s)
{
    cout<<s[s.length()-1];

    if(s.length()==1)
    return; 

    reverse(s.substr(0,s.length()-1));
}

void replacePi(string s)
{
    if(s.length()<=1)
    {
        if(s.length()==1)
        cout<<s;
        return;
    }

    if(s.substr(0,2)=="pi")
    {
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout<<s.substr(0,1);
        replacePi(s.substr(1));
    }
}

int main()
{
    //reverse("binod");
    //string p="pippxxppiixipivu";
    //replacePi(p);
    //towerOfHanoi(3,'A','B','C');
    // cout<<removeDuplicate("aaaaxabbxbbxbcxccxcdxefx")<<"\n";
    // cout<<moveX("aaaaxabbxbbxbcxccxcdxefx");
    //subseq("ABC","");
    // asciisubseq("AB","");
    keypadProb("23","");
    return 0;
}