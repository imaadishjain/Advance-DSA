#include<bits/stdc++.h>
using namespace std;


int count(int n)
{
    int res=0;

    while(n!=0)
    {
        n=n&(n-1);
        res++;
    }

    return res;
}

int main()
{
    int n;
    cout<<"Enter the number=";
    cin>>n;
    
    cout<<"The number of set bits is="<<count(n);
    return 0;

}