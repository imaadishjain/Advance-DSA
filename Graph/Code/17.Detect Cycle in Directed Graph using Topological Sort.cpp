#include<bits/stdc++.h>
using namespace std;


void bfs(int V,vector<int>adj[], vector<int>&indegree)
    {
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
         bfs(V,adj,indegree);
         
        for(int i=0;i<V;i++)
        {
            if(indegree[i]!=0)
            {
                return true;
            }
        }
        
        return false;
    }