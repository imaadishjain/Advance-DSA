#include<bits/stdc++.h>
using namespace std;




int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        if(source==destination)
          {
              return 0;
          }
        int n=grid.size();
        int m=grid[0].size();
        
        int si=source.first;
        int sj=source.second;
        
        int di=destination.first;
        int dj=destination.second;
        
        
        
        queue<pair<int,pair<int,int>>>pq;
    
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[si][sj]=0;
        pq.push({0,{si,sj}});
        int movei[4]={-1,0,1,0};
        int movej[4]={0,-1,0,1};
        
        while(!pq.empty())
        {
            int wt=pq.front().first;
            
            int ni=pq.front().second.first;
            int nj=pq.front().second.second;
            
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int x=ni+movei[i];
                int y=nj+movej[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && dist[x][y]>wt+1)
                {
                    
                        if(x==di && y==dj)
                        {
                            return wt+1;
                        }
                        dist[x][y]=wt+1;
                        pq.push({wt+1,{x,y}});
                    }
                }
            }
            
        
        
        return -1;
    }
        