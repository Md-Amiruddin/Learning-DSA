#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];  //adjacency list for storing graph
bool vis[N];  //visited array

bool dfs(int vertex, int parent){
    vis[vertex] = true;  //marking the current node as visited
    bool isLoopExists = false;
    for(auto child: g[vertex]){  //visiting each child of the current node
        if(vis[child] && child==parent) 
        continue;
        
        if(vis[child]) return true;  //checking if visited before

        isLoopExists |= dfs(child, vertex);  //calling dfs on the child node of current node and continuing recursion
    }

    return isLoopExists;
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
    
    bool isLoopExists = false;
    for(int i = 0 ; i<n ; i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            isLoopExists = true;
            break;
        }
    }

    cout<<isLoopExists;
    return 0;
}