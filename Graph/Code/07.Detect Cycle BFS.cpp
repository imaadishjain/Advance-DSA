#include<bits/stdc++.h>
using namespace std;

  
    bool detectCycle(int s,int V,vector<int> adj[], vector<bool>&visi)
    {
        queue<pair<int,int>>q;
        q.push({s,-1});
        visi[s]=true;
        
        while(!q.empty())
        {
            int n=q.front().first;
            int p=q.front().second;
            q.pop();
            for(auto it: adj[n])
            {
                if(visi[it]==true && it!=p)
                {
                    return true;
                }
                else if(visi[it]==false)
                {
                    q.push({it,n});
                    visi[it]=true;
                }
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>visi(V,false);
    
        for(int i=0;i<V;i++)
        {
            if(!visi[i])
            {
                 if(detectCycle(i,V,adj,visi))
                 {
                     return true;
                 }
            }
        }
        
        return false;
    }