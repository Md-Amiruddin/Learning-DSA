#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int n, int i){
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
        heapify(v, n ,largest);
    }
}

void buildheap(vector<int> &v){
    int n = v.size();
    for(int i = n/2; i>0 ; i--){
        heapify(v,n,i);
    }
}

void heapsort(vector<int> &heap){
    for(int i = heap.size()-1 ; i>1 ; i--){
        swap(heap[1],heap[i]);
        heapify(heap,i-1,1);
    }
}

int main()
{
    vector<int> v({-1,10,30,50,20,35,15});
    buildheap(v); //convert to heap
    heapsort(v);  //sort
    for(auto it: v){
        cout<<it<<" ";
    }
    return 0;
}