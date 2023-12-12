#include<bits/stdc++.h>
using namespace std;


bool isanagram(string s1, string  s2)
{
    if(s1.length()!=s2.length())
    {
        return 0;
    }

    int count[256]={0};

    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(int i=0;i<256;i++)
    {
        if(count[i]!=0)
        {
            return 0;
        }
    }

    return 1; 
}


int main()
{
    string s1;
    string s2;

    cout<<"Enter the first String=";
    cin>>s1;

    cout<<"Enter the second Subse=";
    cin>>s2;
    cout<<std::boolalpha;
    cout<<"Subseq  is of string="<<isanagram(s1,s2);

    return 0;
}