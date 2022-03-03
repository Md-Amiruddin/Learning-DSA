#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v({1,2,2,1,3,1,1,3});
    int k=4;
    map<int,int> mp;
    deque<int> dq;
    vector<int> unique;

    int cnt = 0;
    for(auto it:v){
        dq.push_back(it);
        mp[it]++;
        cnt++;
        if(cnt == k){
            unique.push_back(mp.size());
            mp[dq.front()]--;
            if(mp[dq.front()]==0){
                mp.erase(dq.front());
            }
            dq.pop_front();
            cnt--;
        }
    }

    for(auto it:unique){
        cout<<it<<" ";
    }
    return 0;
}