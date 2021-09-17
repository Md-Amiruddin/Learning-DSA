#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v1(5,1); //creates a vector of size 5 and initializes all elements to 1.
    cout<<"1st element = "<<v1[0]<<" or "<<v1.at(0)<<"Size = "<<v1.size()<<"Capacity = "<<v1.capacity()<<endl;
    
    vector<int> v2(v1);  //creates a vector with same characteristics as v1, equivalent to writing v2=v1.
    v2.push_back(5);
    cout<<"1st element = "<<v2[0]<<" or "<<v2.at(0)<<"Size = "<<v2.size()<<"Capacity = "<<v2.capacity()<<endl;
    
    vector<int> v3; //A vector can also be created without mentioning its size.
    //cout<<"1st element = "<<v3[0]<<" or "<<v3.at(0)<<"Size = "<<v3.size()<<"Capacity = "<<v3.capacity()<<endl;
    cout<<"v3 :- "<<endl;
    v3.push_back(7);
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;
    
    v3.push_back(4);
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;
    
    v3.push_back(8);
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;  //size doubles as more elements are added.
    
    v3.push_back(1);
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;
    
    v3.push_back(5);
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;  //size doubles as more elements are added.

    cout<<"Element at front: "<<v3.front()<<endl;
    cout<<"Element at back: "<<v3.back()<<endl;

    v3.pop_back();  //removes the last element while preserving capacity. Size decreases.
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;

    v3.shrink_to_fit();  //Capacity is shrinked to match the size.
    cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;

    // v3.clear(); //clears the vector, size goes to 0, but capacity remains intact.
    // cout<<"Size = "<<v3.size()<<" Capacity = "<<v3.capacity()<<endl;

    sort(v3.begin(),v3.end(),std::greater<int>()); //for descending order sort
    
    for(int i=0;i<v3.size();++i)  //way 1 to print the vector
    cout<<v3[i];

    cout<<endl;

    for(auto i=v3.begin();i!=v3.end();++i)  //way 2 to print the vector
    cout<<*i;
    
    cout<<endl;

    vector<int>::iterator it;
    for(it=v3.begin();it!=v3.end();++it)  //way 3 to print the vector
    cout<<*it;

    cout<<endl;

    for(auto element:v3) //way 4 to print the vector
    {
        cout<<element;
    }

    cout<<endl;

    swap(v1,v3);  //swaps vectors irrespective of their sizes.

    for(auto element:v3){
        cout<<element;
    }

    cout<<endl;

    return 0;
}