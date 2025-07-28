#include<bits/stdc++.h>
using namespace std;




int findparent(int x, vector<int>&parent)
	{
	    if(x==parent[x])
	    {
	        return x;
	    }
	    
	    return parent[x]=findparent(parent[x],parent);
	}
	
	void unionfind(int x, int y,vector<int>&parent,vector<int>&size)
	{
	    int px=findparent(x,parent);
	    int py=findparent(y,parent);
	    
	    if(px==py)
	    {
	        return;
	    }
	    if(size[px]<size[py])
	    {
	        parent[px]=py;
	        size[py]+=size[px];
	    }
	    else if(size[px]>size[py])
	    {
	        parent[py]=px;
	        size[px]+=size[px];
	    }
	    else
	    {
	         parent[py]=px;
	        size[px]+=size[px];
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++)
        {
            int u=i;
            for(auto it:adj[i])
            {
                int v=it[0];
                int w=it[1];
                
                edges.push_back({w,{u,v}});
                edges.push_back({w,{v,u}});
            }
        }
        
        
        sort(edges.begin(),edges.end());
        vector<int>parent(V+1);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        vector<int>size(V+1,1);
        int mst=0;
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(findparent(u,parent)!=findparent(v,parent))
            {
                unionfind(u,v,parent,size);
                mst+=wt;
            }
        }
        
        
        return mst;
    }