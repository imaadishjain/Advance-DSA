#include<bits/stdc++.h>
using namespace std;


void alldivisor(int n)
{
    int i;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
    }


    for(;i>=1;i--)
    {
        if(n%i==0)
        {
            cout<<n/i<<" ";
        }
    }
}


int main()
{
    int n;
    cout<<"Enter the number=";
    cin>>n;

    cout<<"All the divisor of a number is\n";

    alldivisor(n);
    return 0;
    
}