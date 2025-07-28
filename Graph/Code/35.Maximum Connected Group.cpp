#include<bits/stdc++.h>
using namespace std;




     int findParent(int x,vector<int>&parent)
     {
         if(parent[x]==x)
         {
             return x;
         }
         
         return parent[x]=findParent(parent[x],parent);
     }
     
     void Union(int u, int v,vector<int>&parent,vector<int>&size)
     {
         int pu=findParent(u,parent);
         int pv=findParent(v,parent);
         
         if(pu==pv)
         {
             return;
         }
         if(size[pu]<size[pv])
         {
             parent[pu]=pv;
             size[pv]+=size[pu];
         }
         else if(size[pv]<size[pu])
         {
             parent[pv]=pu;
             size[pu]+=size[pv];
         }
         else
         {
             parent[pv]=pu;
             size[pu]+=size[pv];
         }
     }
    int MaxConnection(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<int>parent(n*n+1);
        vector<int>size(n*n+1,1);
        for(int i=0;i<=n*n;i++)
        {
            parent[i]=i;
        }
        
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }
                
                for(int k=0;k<4;k++)
                {
                    int nr=i+drow[k];
                    int nc=j+dcol[k];
                    
                   
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                         int node=i*n+j;
                        int adjnode=nr*n+nc;
                        Union(node,adjnode,parent,size);
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=1;
                unordered_set<int>st;
                if(grid[i][j]==1)
                {
                    continue;
                }
                
                for(int k=0;k<4;k++)
                {
                    int nr=i+drow[k];
                    int nc=j+dcol[k];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                       int adjnode=nr*n+nc;
                       st.insert(findParent(adjnode,parent));
                    }
                }
                
                for(auto it:st)
                {
                    count+=size[it];
                }
                
                   
                ans=max(ans,count);
                
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            ans=max(ans,size[findParent(i,parent)]);
        }
        
        return ans;
    }