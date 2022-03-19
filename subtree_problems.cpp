#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> g[N];  //adjacency list for storing graph
vector<int> sum(N);
vector<int> evennos(N);

void dfs(int vertex, int parent=0){

    if(vertex%2==0) //if vertex is even increase by 1
    evennos[vertex]++;

    sum[vertex]+=vertex; //taking itself into the sum of subtree

    for(auto child: g[vertex]){  //visiting each child of the current node
        if(child==parent) 
        continue;

        dfs(child,vertex);
        sum[vertex]+=sum[child];  //adding sum of subtree below the current vertex to the current vertex
        evennos[vertex]+= evennos[child];  //adding number of even nos below the current vertex to the count of even in current vertex
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

    cout<<"subtree sum"<<"|even_nos in subtree\n";
    for(int i = 1; i<=n; i++){
        cout<<sum[i]<<" "<<evennos[i]<<"\n";
    }
    return 0;
}