#include<bits/stdc++.h>
using namespace std;


  int timer=1; 
    void bridges(int node, int parent,vector<int>adj[],vector<int>&visited,int tin[], int low[],vector<vector<int>>&b)
    {
        visited[node]=1;
        
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it: adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(visited[it]==0)
            {
             bridges(it,node,adj,visited,tin,low,b);
                
                low[node]=min(low[node],low[it]);
                
                if(low[it]>tin[node])
                {
                    b.push_back({node,it});
                }
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>b;
      vector<int>visited(n,0);

      vector<int>adj[n];

     
          for(auto it:connections)
          {
              adj[it[0]].push_back(it[1]);
              adj[it[1]].push_back(it[0]);
          }
      
       for(int i=0;i<n;i++)
       {
           visited[i]=0;
       }
       int low[n];
       int tin[n];
       bridges(0,-1,adj,visited,tin,low,b);
       
       return b;
    }