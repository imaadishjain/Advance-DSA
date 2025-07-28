#include<bits/stdc++.h>
using namespace std;




void dfs(int i,vector<int>adj[],vector<bool>&visi,stack<int>&st)
    {
        visi[i]=true;
        
        for(auto it:adj[i])
        {
            if(!visi[it])
            {
               dfs(it,adj,visi,st); 
            }
        }
        st.push(i);
    }
    
    string findOrder(string dict[], int N, int K)
    {
        vector<bool>visi(K,false);
        vector<int>adj[K];
        stack<int>st;
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            
            int l=min(s1.length(),s2.length());
            
            for(int j=0;j<l;j++)
            {
                if(s1[j]!=s2[j])
                {
                     adj[s1[j]-'a'].push_back(s2[j]-'a');
                     break;
                }
            }
        }
        
        for(int i=0;i<K;i++)
        {
            if(!visi[i])
            {
                dfs(i,adj,visi,st);
            }
        }
        string str;
        
        while(!st.empty())
        {
            str+=st.top()+'a';
            st.pop();
        }
        
        return str;
        
    }