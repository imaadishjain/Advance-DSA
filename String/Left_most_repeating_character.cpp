#include<bits/stdc++.h>
using namespace std;


int leftmost(string s)
{
    bool visited[256]={0};

    int res=-1;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(visited[s[i]])
        {
            res=i;
        }
        else
        {
            visited[s[i]]=1;
        }
    }

    return res;
}


int main()
{
    string s;

    cout<<"Enter the String=";
    cin>>s;

    cout<<"Left most non repeating character is="<<leftmost(s);

    return 0;
}