#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];  //adjacency list for storing graph
bool vis[N];  //visited array

void dfs(int vertex){
    if(vis[vertex]) return;  //checking if visited before
    vis[vertex] = true;  //marking the current node as visited
    cout<<vertex<<"\n";  //printing the current node
    for(auto child: g[vertex]){  //visiting each child of the current node
        cout<<"Par "<<vertex<<" Child "<<child<<"\n";
        dfs(child);  //calling dfs on the child node of current node and continuing recursion
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m ; i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);  //depth first search
    return 0;
}