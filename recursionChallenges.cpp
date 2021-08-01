#include<iostream>
using namespace std;
bool chksort(int a[],int b)
{
    if(b==1)
    return true;

    if(a[0]<a[1])
    return(chksort(a+1,b-1));
    else
    return(false);
}

void decreasingint(int n)
{
    if(n==0)
    return;

    cout<<n<<" ";
    return(decreasingint(n-1));
}

void increasingint(int n)
{
    if(n==1){
    cout<<n<<" ";
    return;
    }

    increasingint(n-1);
    cout<<n<<" ";
}

int first_occ(int a[], int len, int i, int key)
{
    if(i==len){
        return -1;
    }

    if(a[i]==key){
        return i;
    }
    return(first_occ(a,len,i+1,key));
}

int last_occ(int a[], int len, int i, int key)   
{
    if(i==len){
        return -1;
    }

    int restArray=last_occ(a,len,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    
    if(a[i]==key){
        return i;
    }
    else
    return -1;
}

int main(){
    int a[]={0,6,0,7,3,2,6,354,54,6,0};
    //cout<<chksort(a,5);
    // decreasingint(5);
    // cout<<endl;
    // increasingint(5);
    cout<<last_occ(a,sizeof(a),0,6);          
    return 0;
}