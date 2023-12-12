#include<bits/stdc++.h>
using namespace std;


void powerset(string st)
{
    int l=st.length();
    int psize=(1<<l);

    for(int i=0;i<psize;i++)
    {
        for(int j=0;j<l;j++)
        {
            if((i>>j)&1==1)
            {
                cout<<st[j];
            }
        }
        cout<<endl;
    }
}


int main()
{
    string st;

    cout<<"Enter the string=";
    cin>>st;

    cout<<"Its power set is\n";
    powerset(st);
    return 0;
}