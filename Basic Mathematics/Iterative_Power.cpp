#include<bits/stdc++.h>
using namespace std;

int itpower(int x , int n)
{
    int res=1;

    while(n!=0)
    {
        if(n%2)
        {
            res*=x;
        }

        x*=x;
        n=n/2;
    }

    return res;
}


int main()
{
    int n,x;
    cout<<"Enter the number=";
    cin>>n;

    cout<<"Enter the power=";
    cin>>x;

    cout<<"Power is="<<itpower(n,x);
    return 0;
}