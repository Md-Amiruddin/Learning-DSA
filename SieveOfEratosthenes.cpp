#include<bits/stdc++.h>
using namespace std;
void sieveOfErat(int n)
{
    int i=2;
    int prime[101]={0};
    
    cout<<"prime nos upto "<<n<<" are:\n";
    
    while((i*i)<=n)
    {
        if(prime[i]==0)
        for (int j = i*i; j <= n; j+=i )
        {
            prime[j]=1;
        }
        i++;
    }

    for (i = 2; i <= n; i++)
    {
        if (prime[i]==0)
        {
            cout<<i<<" ";
        }
    }
    
}

void primefactor(int n)
{
    int i;
    int spf[101]={0};          //spf = smallest prime factor
    
    for (i = 2; i <= n; i++)
    {
        spf[i]=i;
    }
        
    i=2;
    while((i*i)<n)
    {
        if(spf[i]==i)
        {
            for (int j = i*i; j <= n; j+=i )
            {
                if(spf[j]==j)
                spf[j]=i;
            }
        }
        i++;
    }

    cout<<"Prime factors of "<<n<<" are:\n";
    while (n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    
    
}

int main()
{
    int n;
    // cout<<"Enter limiting range of Prime nos. to be printed: ";
    // cin>>n;
    // sieveOfErat(n);
    cout<<"Enter a number to find its prime factors: ";
    cin>>n;
    primefactor(n);
    return 0;
}