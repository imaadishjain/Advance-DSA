#include<bits/stdc++.h>
using namespace std;


int lcm(int a, int b)
{
    int res=max(a,b);
   
    while(true)
    {
        if(res%a==0 && res%b==0)
        {
            return res;
        }
        res++;
    }

    return -1;
}


int main()
{
    int a,b;
    cout<<"Enter two number=";
    cin>>a>>b;

    int ans=lcm(a,b);

    cout<<"LCM of two number="<<ans;

    return 0;
}