#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];  //adjacency list for storing graph
vector<int> h(N);
vector<int> d(N);

void dfs(int vertex, int parent=0){


    for(auto child: g[vertex]){  //visiting each child of the current node
        if(child==parent) 
        continue;

        d[child] = d[vertex] + 1;
        dfs(child,vertex);
        if(h[child]+1>h[vertex])  //for taking the maximum height from amongst all the child nodes
        h[vertex]= h[child] + 1;
    }

}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n-1 ; i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    dfs(1);

    for(int i = 1; i<=n; i++){
        cout<<d[i]<<" "<<h[i]<<"\n";
    }
    return 0;
}