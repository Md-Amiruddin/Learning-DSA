#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];  //adjacency list for storing graph
bool vis[N];  //visited array

vector<vector<int>> cc; //stores the connected components
vector<int> current_cc;  //keeps storing connected components while in a running dfs

void dfs(int vertex){
    if(vis[vertex]) return;  //checking if visited before
    vis[vertex] = true;  //marking the current node as visited

    current_cc.push_back(vertex);  //storing the current vertex into the temporary connected component list
    
    for(auto child: g[vertex]){  //visiting each child of the current node
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
    
    int cnt = 0;
    for(int i = 1; i<=n ; i++){
        if(vis[i]) continue;
        current_cc.clear();  //clearing the list before storing the connected components in the next iteration of dfs.
        dfs(i);
        cc.push_back(current_cc);  //building list of connected components
        cnt++;
    }

    cout<<"Number of connected components: "<<cnt<<"\n";
    cout<<"Connected components:\n";
    for(int i = 0; i<cc.size(); i++){
        for(auto it:cc[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }

    return 0;
}