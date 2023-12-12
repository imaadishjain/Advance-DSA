#include<bits/stdc++.h>
using namespace std;


void patternsearch(string s1, string s2)
{
    
    for(int i=0;i<=s1.length()-s2.length();)
    {
        int j;
        for(j=0;j<s2.length();j++)
        {
            if(s1[i+j]!=s2[j])
            {
                break;
            }
        }

        if(j==s2.length())
        {
           cout<<i<<" ";
           i+=j;
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                i+=j;
            }
        }
    }
}


int main()
{
    string s1;
    string s2;

    cout<<"Enter the  text=";
    cin>>s1;

    cout<<"Enter the pattern=";
    cin>>s2;
    cout<<std::boolalpha;
    cout<<"Pattern   is of text\n";
    patternsearch(s1,s2);

    return 0;
}