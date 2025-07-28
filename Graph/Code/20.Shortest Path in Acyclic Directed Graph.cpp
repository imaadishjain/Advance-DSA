#include<bits/stdc++.h>
using namespace std;






void topo(int i,vector<pair<int,int>>adj[],stack<int>&st,vector<bool>&visi)
     {
         visi[i]=true;
         
         for(auto it: adj[i])
         {
             if(!visi[it.first])
             {
                 topo(it.first,adj,st,visi);
             }
         }
         
         st.push(i);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
         vector<pair<int,int>>adj[N];
         
         vector<int>dist(N,1e9);
         dist[0]=0;
         
         vector<bool>visi(N,false);
         
        stack<int>st;
        
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        
        for(int i=0;i<N;i++)
        {
            if(!visi[i])
            {
                topo(i,adj,st,visi);
            }
        }
        
        
        while(!st.empty())
        {
            int u=st.top();
            st.pop();
            
            for(auto it:adj[u])
            {
                dist[it.first]=min(dist[it.first],dist[u]+it.second);
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        
        return dist;
     }