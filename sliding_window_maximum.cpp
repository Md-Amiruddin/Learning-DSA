#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int a[] = {1,3,-1,-3,5,3,6,7};
int n = sizeof(a)/sizeof(int);
int k = 3;

int main()
{
    deque<int> dq;
    vector<int> v;
    int i;

    for(i=0;i<k;i++){
        while((!dq.empty()) && a[dq.back()] <= a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(; i < n ; i++){

        //push the largest element into the resulting vector
        v.push_back(a[dq.front()]);
        
        //removing all elements which are not present in the current window.
        while((!dq.empty()) && dq.front() <= i-k)
        dq.pop_front();

        //removing all elements which are smaller than the current element.
        while((!dq.empty()) && a[i]>=a[dq.back()])
        dq.pop_back();

        dq.push_back(i);

    }

    v.push_back(a[dq.front()]);

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}