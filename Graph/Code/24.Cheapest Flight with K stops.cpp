#include<bits/stdc++.h>
using namespace std;




int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        
        
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int distance=q.front().second.second;
            q.pop();
            if(stops>K)
            {
                continue;
            }
            for(auto it: adj[node])
            {
                int adjNode=it.first;
                int wt=it.second;
                
                if(dist[adjNode]>wt+distance)
                {
                    dist[adjNode]=wt+distance;
                    q.push({stops+1,{adjNode,wt+distance}});
                }
            }
        }
        
        
        return dist[dst]==1e9?-1:dist[dst];
    }