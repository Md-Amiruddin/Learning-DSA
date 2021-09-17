#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main()
{
    array <int,8> arr={10,16,7,14,5,3,12,9};
    vector <pair<int,int>> v;
    for(int i=0; i<arr.size(); ++i){
        v.push_back(make_pair(i,arr[i]));
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0 ; i<arr.size() ; ++i){
        arr[v.at(i).first]=i;
    }

    for(auto element:arr){
        cout<<element<<" ";
    }

    return 0;
}