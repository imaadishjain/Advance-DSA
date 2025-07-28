#include<bits/stdc++.h>
using namespace std;

  bool detectCycle(int s,int p,vector<int>adj[], vector<bool>&visi)
    {
        visi[s]=true;
        
        for(auto it: adj[s])
        {
            if(visi[it] && it!=p)
            {
               return true;
            }
            else if(!visi[it])
            {
               if(detectCycle(it,s,adj,visi))
               {
                   return true;
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
                 if(detectCycle(i,-1,adj,visi))
                 {
                     return true;
                 }
            }
        }
        
        return false;
    }