#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
    {
        vector<pair<int,int>>adj[V];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        
        for(int i=0;i<V-1;i++)
        {
           for(int j=0;j<V;j++)
           {
               if(dist[j]!=1e8)
               {
               for(auto it: adj[j])
               {
                   int v=it.first;
                   int wt=it.second;
                   if( dist[v]>wt+dist[j])
                   {
                       dist[v]=wt+dist[j];
                   }
               }
               }
           }
        }
        
        
           for(int j=0;j<V;j++)
           {
               if(dist[j]!=1e8)
               {
               for(auto it: adj[j])
               {
                   int v=it.first;
                   int wt=it.second;
                   if(dist[v]>wt+dist[j])
                   {
                       return {-1};
                   }
               }
               }
           }
           
           return dist;
    }