#include<bits/stdc++.h>
using namespace std;



	void dfs(int node,vector<int>&visi,vector<vector<int>>&adj,stack<int>&st)
	{
	    visi[node]=1;
	    
	    for(auto it: adj[node])
	    {
	        if(!visi[it])
	       {
	        dfs(it,visi,adj,st);
	       }
	    }
	    st.push(node);
	}
	
	void dfs2(int node,vector<int>&visi,vector<int>adjT[])
	{
	    visi[node]=1;
	    
	    for(auto it: adjT[node])
	    {
	        if(!visi[it])
	       {
	        dfs2(it,visi,adjT);
	       }
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       vector<int>visi(V,0);
       stack<int>st;
       for(int i=0;i<V;i++)
       {
               if(!visi[i])
               {
                   dfs(i,visi,adj,st);
               }
           
       }
       
       
       vector<int>adjT[V];
       
       for(int i=0;i<V;i++)
       {
           visi[i]=0;
           for(auto it: adj[i])
           {
               adjT[it].push_back(i);
           }
       }
       int ans=0;
      
       while(!st.empty())
       {
         int node=st.top();
         st.pop();
         if(!visi[node])
         {
            ans++;
             dfs2(node,visi,adjT);
         }
       }
       return ans;
    }