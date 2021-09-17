#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "heythere";
    vector<int> v{1, 2, 3};
    array<int, 3> y = {1, 2, 3};
    int a = 4, b = 6;

    cout << max(a, b) << endl; //returns max of 2 numbers
    cout << min(a, b) << endl; //returns min of 2 numbers
    
    swap(a, b);                //swaps values of 2 variables,vector,array.
    
    cout << "a = " << a << " "
         << "b = " << b << endl;
    
    reverse(s.begin(), s.end()); //reverses string,vector.
    
    cout << s << endl;
    
    reverse(v.begin(), v.end());
    
    for (auto element : v) //iterator, can print array, stl array, vectors.
    {
        cout << element << " ";
    }

    cout << endl;
    vector<int> q = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Binary Search for 1: " << binary_search(q.begin(), q.end(), 1) << endl; //binary_search for array,vector.
    reverse(q.begin(), q.end());
    cout << "Binary Search for 1 in reversed array: " << binary_search(q.end(), q.begin(), 1)<<endl; //if array is in descending order binary_search parameters of start and end are reversed.
    //binary_search(q.begin(),q.end(),1,greater<int>()) also will work the same way as above.

    reverse(q.begin(), q.end()); //vector returned to original sequence.


    
    
    // | vector rotation |
    rotate(q.begin(),q.begin()+3,q.end()); //rotate left
    for(auto i:q){
        cout<<i<<" ";
    }

    cout<<endl;

    rotate(q.begin(),q.end()-3,q.end());  //rotate right
    for(auto i:q){
        cout<<i<<" ";
    }

    cout<<endl;




    // |lowerbound / upperbound functions|
    
    //lowerbound
    auto it = lower_bound(q.begin(),q.end(),6); //returns an iterator pointing to 6 or to an element greater than and closest to 6 in a sorted sequence.
    cout<< (it!=q.end() ? to_string(*it) : "Not found")<<endl;
    //how does it!=q.end() works if the element being searched for is the last element?
    cout<<*(q.end()-1)<<endl;  //q.begin() points to the 1st element, q.end() points to the memory location of last element + 1, that's why it!=q.end() in 2 lines before works!

    //upperbound
    auto it2 = upper_bound(q.begin(),q.end(),3); //returns an iterator pointing to first element greater than 3 in a sorted sequence.
    cout<< (it2!=q.end() ? to_string(*it2) : "Not found")<<endl;
    



    // |Distance function|
    cout<<distance(q.begin(),it2)<<endl; //returns the distance between 2 memory addresses.

    string g="Dimple";
    cout<<distance(g.begin(),g.end())<<endl;  //can also be used on string. This particular invokation works same as g.length() which is used to find length of string
    
    return 0;
}