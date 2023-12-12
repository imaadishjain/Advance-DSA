#include<bits/stdc++.h>
using namespace std;


bool anagrampat(string txt, string pat)
{
    int n= pat.length();

    for(int i=0;i<txt.length()-n;i++)
    {
        if(is_permutation(txt.begin()+i,txt.begin()+n+i,pat.begin()))
        {
            return 1;
        }
    }

    return 0;
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
    cout<<"Pattern   is of anagram text="<<anagrampat(s1,s2);

    return 0;
}