#include <bits/stdc++.h>
using namespace std;


// DFS
	void dfs(int i,  vector<int>adj[], vector<bool>&visi,stack<int>&st)
	{
	    visi[i]=true;
	    
	    for(auto it: adj[i])
	    {
	        if(!visi[it])
	        {
	            dfs(it,adj,visi,st);
	        }
	    }
	    
	    st.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    vector<bool>visi(V,false);
	    
	    stack<int>st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visi[i])
	        {
	            dfs(i,adj,visi,st);
	        }
	    }
	    
	    
	    while(!st.empty())
	     {
	         ans.push_back(st.top());
	         st.pop();
	     }
	     
	     return ans;

	}



    //BFS

    vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int>indegree(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            for(auto it :adj[i])
            {
                indegree[it]++;
            }
        }
        
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
            ans.push_back(node);
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
        
        return ans;
	}