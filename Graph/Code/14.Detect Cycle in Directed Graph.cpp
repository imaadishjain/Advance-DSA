
#include <bits/stdc++.h>
using namespace std;



bool dfs(int i,vector<int>adj[],vector<bool>&visi,vector<bool>&path)
    {
        visi[i]=true;
        path[i]=true;
        
        for(auto it: adj[i])
        {
            if(visi[it] && path[it])
            {
                return true;
            }
            else if(!visi[it])
            {
                
                if(dfs(it,adj,visi,path))
                {
                   return true; 
                }
            }
        }
        path[i]=false;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool>visi(V,false);
        
        vector<bool>path(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(dfs(i,adj,visi,path))
            {
                return true;
            }
          
        }
        
        return false;
        
    }