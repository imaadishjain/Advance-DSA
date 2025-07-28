 #include <bits/stdc++.h>
using namespace std;

 
 
 
 vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<bool>visi(V+1,false);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        visi[0]=true;
        while(!q.empty())
        {
            
            int t=q.front();
            ans.push_back(t);
            q.pop();
            for(auto it: adj[t])
            {  if(!visi[it])
                {
                    visi[it]=true;
                    q.push(it);
                }
            }
        }
        return ans;
    }