#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i){
    int n = v.size();
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left<n  && v[left]>v[largest]){
        largest = left;
    }
    if(right<n && v[right]>v[largest]){
        largest = right;
    }

    if(largest != i){
        swap(v[largest],v[i]);
        heapify(v,largest);
    }
}

void buildheap(vector<int> &v){
    int n = v.size();
    for(int i = n/2; i>0 ; i--){
        heapify(v,i);
    }
}

int main()
{
    vector<int> v({-1,10,30,50,20,35,15});
    buildheap(v);
    for(auto it: v){
        cout<<it<<" ";
    }
    return 0;
}