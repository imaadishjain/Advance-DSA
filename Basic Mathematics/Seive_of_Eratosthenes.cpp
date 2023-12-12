#include<bits/stdc++.h>
using namespace std;

void seive(int n)
{
    vector<bool>isprime(n+1,true);

    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
          {
              for(int j=i*i;j<=n;j+=i)
              {
                isprime[j]=false;
              }
          }
    }


    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            cout<<i<<" ";
        }
    }
}


int main()
{
    int n;
    cout<<"Enter the number=";
    cin>>n;

    cout<<"All the prime number less than "<<n<<"is\n";
    seive(n);
    return 0;
}