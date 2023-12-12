#include<bits/stdc++.h>
using namespace std;

bool checkrotation(string s1, string s2)
{
    if(s1.length()!=s2.length())
    {
        return 0;
    }

    return (s1+s1).find(s2)!=string::npos;
}


int main()
{
    string s1;
    string s2;

    cout<<"Enter the  Original string=";
    cin>>s1;

    cout<<"Enter the Rotated string=";
    cin>>s2;
    cout<<std::boolalpha;
    cout<<"String is rotated="<<checkrotation(s1,s2);

    return 0;
}