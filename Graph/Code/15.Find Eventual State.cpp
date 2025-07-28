
#include <bits/stdc++.h>
using namespace std;




bool dfs(int i, vector<int>adj[],vector<bool>&visi,vector<bool>&path,set<int>&st)
    {
        visi[i]=true;
        path[i]=true;
        
        for(auto it: adj[i])
        {
            if(visi[it] && path[it])
            {
               return false;
            }
            else if(!visi[it])
            {
                if(!dfs(it,adj,visi,path,st))
                {
                    return false;
                }
            }
            
        }
        st.insert(i);
        path[i]=false;
        return true;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        set<int>st;
        vector<bool>visi(V,false);
        vector<bool>path(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!visi[i])
            {
                dfs(i,adj,visi,path,st);
            }
        }
        
        vector<int>ans(st.begin(),st.end());
        
        
        return ans;
    }