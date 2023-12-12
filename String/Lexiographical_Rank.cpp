#include<bits/stdc++.h>
using namespace std;


int lexiorank(string str)
{
    int count[256]={0};
    int n=str.length();
    int fac=1;
    for(int i=1;i<=n;i++)
    {
      fac*=i;;
    }

    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }

    for(int i=1;i<256;i++)
    {
      count[i]+=count[i-1];
    }

    int res=1;

    for(int i=0;i<n-1;i++)
    {
        fac=fac/(n-i);
        res=res+count[str[i]-1]*fac;


        for(int j=str[i];j<256;j++)
        {
            count[j]--;
        }
    }
    return res;
}

int main()
{
    string s;

    cout<<"Enter the  string=";
    cin>>s;

    cout<<"Lexiographic rank of a given string is ="<<lexiorank(s);

    return 0;
}

