#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;                              //it is not possible to change the address of a variable
    *b=temp;
}
int main()
{
    int a=1,b=6;
    swap(&a,&b);
    cout<<a<<" "<<b;
    return 0;
}