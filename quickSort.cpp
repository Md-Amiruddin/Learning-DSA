#include<bits/stdc++.h>
using namespace std;

void swap_func(int a[], int pos1, int pos2)
{
    int temp=a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=temp;
}

int partition(int a[], int l, int h)
{
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(a[i]<=pivot && i<h)
        i++;
        while(a[j]>=pivot && j>l)
        j--;

        if(i<j)
        swap_func(a, i,j);
    }
    swap_func(a, j,l);
    return j;
}

void quicksort(int a[], int l, int h)
{
    if(l<h)
    {
        int pivot=partition(a, l, h);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,h);
    }
}

int main()
{
    int a[5]={8,3,6,1,7};

    quicksort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}