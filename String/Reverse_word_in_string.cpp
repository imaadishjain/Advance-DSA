#include<bits/stdc++.h>
using namespace std;

void reverseword(string &s)
{
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            reverse(s.begin()+j,s.begin()+i);
            j=i+1;
        }
    }

    reverse(s.begin()+j,s.end());
    reverse(s.begin(),s.end());
}


int main()
{
    string s;

    cout<<"Enter the String=";
    getline(cin,s);

    cout<<"New String after reversing word\n";
    reverseword(s);
    cout<<s<<endl;

    return 0;
}