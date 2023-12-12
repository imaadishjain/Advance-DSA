#include<bits/stdc++.h>
using namespace std;

bool isSafe(string str, int l,int i,int r)
{
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
    {
        return 0;
    }
    if(l+1==r && str[l]=='B' && str[i]=='A')
    {
        return 0;
    }

    return 1;
}
void permutation(string str,int l, int r)
{
    if(l==r)
    {
        cout<<str<<endl;
    }

    for(int i=l;i<=r;i++)
    {
        if(isSafe(str,l,i,r))
        {
        swap(str[l],str[i]);
        permutation(str,l+1,r);
        swap(str[l],str[i]);
        }
    }
}

int main()
{
    string str="ABC";

    permutation(str,0,2);

    return 0;
}