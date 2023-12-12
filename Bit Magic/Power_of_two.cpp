#include<bits/stdc++.h>
using namespace std;


bool poweroftwo(int n)
{
    return !(n && (n&(n-1)));
}

int main()
{
    int n;
    cout<<"Enter the number=";
    cin>>n;
    cout<<std::boolalpha;
    cout<<"The number can be represented in power of two="<<poweroftwo(n);
    return 0;
}