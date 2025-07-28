#include<bits/stdc++.h>
using namespace std;

 int m=(int)(1e9+7);
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        
        dist[0]=0;
        ways[0]=1;
        
     priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int u=pq.top().second;
            long distance=pq.top().first;
            pq.pop();
            
            for(auto it: adj[u])
            {
                int v=it.first;
                int wt=it.second;
                
                if(dist[v]>wt+distance)
                {
                    dist[v]=wt+distance;
                    ways[v]=ways[u];
                    pq.push({wt+distance,v});
                }
                else if(dist[v]==wt+distance)
                {
                    ways[v]=(ways[v]+ways[u])%m;
                }
            }
        }
        
        
        return ways[n-1]%m;
        
     
    }