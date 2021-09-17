#include<iostream>
#include<array>
#include<algorithm>
#include<iterator>
using namespace std;
void testfun(array<int,4> &n)  //doesn't make a copy of array, original array is altered.
{
    sort(n.begin(),n.end());
}

void testfun2(array<int,4> n)   //makes a copy, original array is preserved.
{
    sort(n.begin(),n.end());
}

void multiDimArr(array<array<int,3>,3> u)
{
    int z;
    for(auto i=u.begin();i!=u.end();++i)  //Multidimensional array iterator.
    {
        for(auto j=(*i).begin();j!=(*i).end();++j)
        cout<<*j<<" ";
        cout<<"   ";
    }
}

int main()
{
    array<int,4> a = {5,2,4,8};
    array<int,4> b { {7,9,0,3} };
    
    testfun(a);
    testfun2(b);

    // b=a; <--an array can be copied to another array with this. Only in stl array,not possible in normal array.

    cout << "Number of elements in the array are : " << a.size() << std::endl;
    cout << "First element of array : " << a.front() << std::endl;
    cout << "Last element of array : " << a.back() << std::endl;
    cout << "Is array empty? (0(false)/1(true)) : " << a.empty() << std::endl;
    cout << "Max elements array can hold : " << a.max_size() << std::endl;
    // a.fill(2); <-- fills the array with the same specified value.
    // a.swap(b); <-- swaps one array with another.
    for(auto i= a.begin(); i!=a.end(); ++i)    //iterator used to iterate over the array
    cout<<*i<<" ";
    cout<<endl;

    cout<<a.begin()<<" "<<a.end()<<endl;
    // a.begin() , a.end() returns the memory address of starting and ending poisions of the array respectively.

    //Multidimensional array
    array<array<int,3>,3> y { { {1,2,3}, {4,5,6}, {7,8,9} } } ;
    multiDimArr(y);
    cout<<endl;

    cout<<"Array a:"<<endl;
    for(int i=0;i<a.size();i++)
    cout<<a.at(i)<<" "<<a[i]<<endl;  //a.at(i) or a[i] both can be used.
    cout<<"Array b:"<<endl;
    for(int i=0;i<a.size();i++)
    cout<<b.at(i)<<" "<<b[i]<<endl;
    
    return 0;
}