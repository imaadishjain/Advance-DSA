#include<bits/stdc++.h>
using namespace std;





void bfs(int i, int j,vector<vector<char>>&g,vector<vector<int>>&visi)
    {
        int n=g.size();
        int m=g[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visi[i][j]=1;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int row=-1;row<=1;row++)
            {
                if(x+row>=0 && x+row<n)
                {
                for(int col=-1;col<=1;col++)
                {
                    if(y+col>=0 && y+col<m && !visi[row+x][col+y] && g[row+x][y+col]=='1')
                    {
                        q.push({x+row,y+col});
                        visi[x+row][y+col]=1;
                    }
                }
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        
        vector<vector<int>>visi(n,vector<int>(m,0));
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                
                if( !visi[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,grid,visi);
                    count++;
                }
            }
            
        }
        
        return count;
    }