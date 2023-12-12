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