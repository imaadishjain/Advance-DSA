#include<bits/stdc++.h>
using namespace std;


bool checksubseq(string s1,string s2)
{
    int i=0;
    int j=0;

    while(i<s1.length() && j<s2.length())
    {
        if(s1[i]==s2[j])
        {
            i++;j++;
        }
        else
        {
        i++;
        }
    }

    return j==s2.length();
}


int main()
{
    string s1;
    string s2;

    cout<<"Enter the String=";
    cin>>s1;

    cout<<"Enter the Subse=";
    cin>>s2;
    cout<<std::boolalpha;
    cout<<"Subseq  is of string="<< checksubseq(s1,s2);


    return 0;
}