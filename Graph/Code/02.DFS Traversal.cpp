#include <bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int>adj[],vector<bool>&visi,vector<int>&ans)
    {
        visi[i]=true;
        ans.push_back(i);
        for(auto it: adj[i])
        {
            if(!visi[it])
            {
                
                dfs(it,adj,visi,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool>visi(V+1,false);
        vector<int>ans;
       
        dfs(0,adj,visi,ans);
        
        return ans;
    }