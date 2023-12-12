#include<bits/stdc++.h>
using namespace std;


int prefix(string s)
{
    stack<int>st;

    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>=48 && s[i]<=57)
        {
           st.push(s[i]-48);
        }
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            if(s[i]=='/')
            {
                st.push(op1/op2);
            }
            if(s[i]=='+')
            {
                st.push(op1+op2);
            }
            if(s[i]=='-')
            {
                st.push(op1-op2);
            }
            if(s[i]=='*')
            {
                st.push(op1*op2);
            }
        }
    }

    return st.top();
}

int main()
{
    string str;

    cout<<"Enter the prefix expression\n";
    cin>>str;

    cout<<"Evaluation of Prefix expression is="<<prefix(str);

    return 0;
}