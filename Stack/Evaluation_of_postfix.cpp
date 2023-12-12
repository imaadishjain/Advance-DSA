#include<bits/stdc++.h>
using namespace std;



int postfix(string s)
{
    stack<int>st;

    for(int i=0;i<s.length();i++)
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
                st.push(op2/op1);
            }
            if(s[i]=='+')
            {
                st.push(op2+op1);
            }
            if(s[i]=='-')
            {
                st.push(op2-op1);
            }
            if(s[i]=='*')
            {
                st.push(op2*op1);
            }
        }
    }

    return st.top();
}

int main()
{
    string str;

    cout<<"Enter the postfix expression\n";
    cin>>str;

    cout<<"Evaluation of Postfix expression is="<<postfix(str);

    return 0;
}