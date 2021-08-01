
#include<iostream>
using namespace std;
int main()
{
	int n,x,i,j,min,temp;
	cin>>n;
	int arr[n];
	for(i=0; i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0; i< n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
        if(min!=i){
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
        }
	}
    for(j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
	return 0;
}