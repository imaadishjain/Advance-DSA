#include <bits/stdc++.h>
using namespace std;

// DFS

bool  dfs(int i,int c,vector<int>adj[], vector<int>&visi)
    {
        visi[i]=c;
        for(auto it: adj[i])
        {
            if(visi[it]==-1)
            {
                if(!dfs(it,!c,adj,visi))
                {
                    return false;
                }
            }
            else if(c==visi[it])
            {
              return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    
	    vector<int>vec(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(vec[i]==-1)
	        {
	            if(!dfs(i,0,adj,vec))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}



    //BFS



    bool bfs(int i,vector<int>adj[],vector<int>&visi)
    {
        queue<int>q;
        q.push(i);
        visi[i]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        
	        for(auto it: adj[node])
	        {
	            if(visi[it]==-1)
	            {
	               q.push(it);
	               visi[it]=!visi[node];
	            }
	            else if(visi[it]==visi[node])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    
	    vector<int>visi(V,-1);

	    for(int i=0;i<V;i++)
	    {
	        if(visi[i]==-1)
	        {
	       
	              if(bfs(i,adj,visi)==false)
	              {
	                  return false;
	              }
	        }
	    }
	   
	    return true;
	}
