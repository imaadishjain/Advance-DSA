#include <bits/stdc++.h>
using namespace std;
 
 // DFS that visit all node
 void dfs(int i,vector<int>g[],vector<bool>&visi)
    {
        visi[i]=true;
        for(auto it:g[i])
        {
            if(!visi[it])
            {
            dfs(it,g,visi);
            }
        }
    }


    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<int>g[V];
        vector<bool>visi(V,false);

        // Converting Adjancey matrix to Adjancey List

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        // Counting Provinces
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(visi[i]==false)
            {
                dfs(i,g,visi);
                count++;
            }
        }
        
        return count;
    }