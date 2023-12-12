#include<bits/stdc++.h>
using namespace std;


void check(int n, int k)
{
   if((n>>(k-1))&1==1)
   {
    cout<<"Yes\n";
   }
   else
   {
    cout<<"No\n";
   }
}

int  main()
{
    int n,k;
    cout<<"Enter the value of n=";
    cin>>n;

    cout<<"Enter the value of k=";
    cin>>k;

    cout<<"The kth bit is set=";
    check(n,k);
    return 0;
}