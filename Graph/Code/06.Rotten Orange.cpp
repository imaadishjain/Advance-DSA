#include<bits/stdc++.h>
using namespace std;

 int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int cntFresh=0;
        vector<vector<int>>solve=grid;
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(grid[i][j]==2)
              {
                  q.push({{i,j},0});
              }
              else if(grid[i][j]==1)
              {
                  cntFresh++;
              }
            }
        }
        
        int t=0;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int s=q.front().second;
            q.pop();
            t=max(t,s);
            
            for(int i=0;i<4;i++)
            {
                int r=x+row[i];
                int c=y+col[i];
                
                if(r>=0 && r<n && c>=0 && c<m && solve[r][c]==1)
                {
                    cntFresh--;
                    q.push({{r,c},s+1});
                    solve[r][c]=2;
                }
            }
        }
        
        
        
        return cntFresh==0?t:-1;
    }