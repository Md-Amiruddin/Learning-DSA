#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r)   //to merge the two incoming sorted halfs of a[]
{
    /**Two sub arrays are declared which store 2 halfs of the array**/
    int len_b=mid-l+1;
    int len_c=r-(mid+1)+1;
    int b[len_b];
    int c[len_c];

    for(int i=0;i<len_b;i++)         //storing the 2 halfs of a[] in b[] and c[].
    {
        b[i]=a[i+l];
    }
    
    for(int i=0;i<len_c;i++)
    {
        c[i]=a[i+mid+1];
    }

    int head_b=0;    //heads traverse the respective sub arrays.
    int head_c=0;
    int countr = l;

    while (head_b<len_b && head_c<len_c)        //minimum element among the two sub arrays in the current index are taken and stored in a[];
    {
        if (b[head_b] < c[head_c])
        {
            a[countr]=b[head_b];
            head_b++;
            countr++;
        }
        else
        {
            a[countr]=c[head_c];
            head_c++;
            countr++;
        }
    }

    while(head_b<len_b){           //to make sure both the sub arrays are exhausted fully and its elements copied over to a[];
        a[countr]=b[head_b];
        head_b++;
        countr++;
    }

    while(head_c<len_c){
        a[countr]=c[head_c];
        head_c++;
        countr++;
    }
}

void mergeSort(int a[], int l, int r)
/**index of leftmost element=l, rightmost element=r of the incoming array pointer.
 * Yes it is an arraypointer thats why no return type is used in entire program, the changes are made in the original array.
**/
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

int main()
{
    int a[5]={5,4,3,2,1};
    mergeSort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<"  ";
    }
    return 0;
}