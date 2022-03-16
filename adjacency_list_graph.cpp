#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<pair<int,int>> g[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m ; i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g[v1].push_back(make_pair(v2,wt));
        g[v2].push_back(make_pair(v1,wt));
    }

    for(int i = 0; i<n; i++){
        for(auto it: g[i]){
            cout<<i<<" "<<it.first<<" wt: "<<it.second<<" | ";
        }
        cout<<"\n";
    }
    return 0;
}