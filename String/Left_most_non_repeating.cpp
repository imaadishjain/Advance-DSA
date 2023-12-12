#include<bits/stdc++.h>
using namespace std;


int rightmost(string s)
{
    int visited[256]={0};

    int res=INT_MAX;
    for(int i=s.length()-1;i>=0;i--)
    {
          visited[s[i]]++;
    }

   for(int i=0;i<s.length();i++)
   {
    if(visited[s[i]]==1)
    {
        res=min(res,i);
    }
   }

   return res==INT_MAX?-1:res;
}


int main()
{
    string s;

    cout<<"Enter the String=";
    cin>>s;

    cout<<"Right most non repeating character is="<<rightmost(s);

    return 0;
}