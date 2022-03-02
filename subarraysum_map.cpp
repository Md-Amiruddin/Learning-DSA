#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v({10,15,-5,15,-10,5});
    map<int,int> mp;
    int cursum = 0;
    int reqsum = 5;
    int left = -1;
    int right = -1;
    for(int i = 0; i<v.size(); i++){
        cursum+=v[i];
        map<int,int> :: iterator it = mp.find(cursum-reqsum);
        if(it != mp.end()){
            left = (it)->second;
            left ++;
            right = i;
            break;
        }   
        mp[cursum]=i;
    }
    cout<<left<<" "<<right;
    return 0;
}