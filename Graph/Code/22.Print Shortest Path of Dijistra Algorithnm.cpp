#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n,int m,vector<vector<int>>&edge)
{
    vector<pair<int,int>>adj[n+1];

    for(int i=0;i<m;i++)
    {
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }

    vector<int>parent(n+1,0);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    vector<int>dist(n+1,1e9);
    dist[1]=0;


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});


    while(!pq.empty())
    {
        int u=pq.top().second;
        int distance=pq.top().first;

        pq.pop();

        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;

            if(dist[v]>wt+distance)
            {
               parent[v]=u;
               dist[v]=wt+distance;
               pq.push({wt+distance,v});
            }
        }
    }

   if(dist[n]==1e9)
   {
    return {-1};
   }
    vector<int>path;

    while(parent[n]!=n)
    {
        path.push_back(n);
        n=parent[n];
    }
    
    path.push_back(1);
    reverse(path.begin(),path.end());

    return path;


}