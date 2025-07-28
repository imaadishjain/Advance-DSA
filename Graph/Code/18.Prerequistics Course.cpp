#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites)
	{
	    vector<int>indegree(N,0);
	    vector<int>adj[N];
	    
	    for(auto it: prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    
	    for(int i=0;i<N;i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    int count=0;
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        count++;
	        
	        
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    
	    
	    return count==N;
	}