#include<bits/stdc++.h>
using namespace std;

int joes(int n, int k)
{
    if(n==1)
    {
        return 0;
    }

    return (joes(n-1,k)+k)%n;
}


int main()
{
    int n,k;
    cout<<"Enter the number of candidates=";
    cin>>n;

    cout<<"Enter the value of k=";
    cin>>k;

    cout<<"Survivor candidate is="<<joes(n,k);


    return 0;
}