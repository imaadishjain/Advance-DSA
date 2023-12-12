#include<bits/stdc++.h>
using namespace std;

int trailing(int n)
{
    int res=0;

    for(int i=5;i<=n;i*=5)
    {
        res+=n/i;
    }

    return res;
}


int main()
{
    int n;
    cout<<"Enter the number=";
    cin>>n;

    int ans=trailing(n);

    cout<<"Trailing zero in factorial is="<<ans<<endl;

    return 0;
}