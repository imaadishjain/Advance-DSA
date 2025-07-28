#include <bits/stdc++.h>>
using namespace std;



// By using-DFS

 int  dfs(int i, int j,int deltarow[],int deltacol[],vector<vector<int>>grid,vector<vector<bool>>&visi)
    {
        int n=grid.size();
        int m=grid[0].size();
        visi[i][j]=true;
      
        for(int k=0;k<4;k++)
        {
            int x=i+deltarow[k];
            int y=j+deltacol[k];
            
            if(x>=0 && x<n && y>=0 && y<m && !visi[x][y] && grid[x][y]==1)
            {
                dfs(x,y,deltarow,deltacol,grid,visi);
            }
        }
        
    }
     
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int deltarow[]={-1,0,1,0};
        int deltacol[]={0,1,0,-1};
      
      vector<vector<bool>>visi(n,vector<bool>(m,false));
      
      for(int i=0;i<n;i++)
      {
          
          if(!visi[i][0] && grid[i][0]==1)
          {
              dfs(i,0,deltarow,deltacol,grid,visi);
          }
          if(!visi[i][m-1] && grid[i][m-1]==1)
          {
              dfs(i,m-1,deltarow,deltacol,grid,visi);
          }
      }
      
      for(int j=0;j<m;j++)
      {
          if(!visi[0][j] && grid[0][j]==1)
          {
              dfs(0,j,deltarow,deltacol,grid,visi);
          }
          if(!visi[n-1][j] && grid[n-1][j]==1)
          {
              dfs(n-1,j,deltarow,deltacol,grid,visi);
          }
      }
      int count=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(!visi[i][j] && grid[i][j]==1)
              {
                  count++;
              }
          }
      }
        return count;
    }




//By using BFS




int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int deltarow[]={-1,0,1,0};
        int deltacol[]={0,1,0,-1};
         
      vector<vector<bool>>visi(n,vector<bool>(m,false));
      
      queue<pair<int,int>>q;
      
      
      for(int i=0;i<n;i++)
      {
          
          if(!visi[i][0] && grid[i][0]==1)
          {
              q.push({i,0});
              visi[i][0]=1;
          }
          if(!visi[i][m-1] && grid[i][m-1]==1)
          {
              q.push({i,m-1});
              visi[i][m-1]=1;
          }
      }
      
      for(int j=0;j<m;j++)
      {
          if(!visi[0][j] && grid[0][j]==1)
          {
               q.push({0,j});
              visi[0][j]=1;
          }
          if(!visi[n-1][j] && grid[n-1][j]==1)
          {
              q.push({n-1,j});
              visi[n-1][j]=1;
          }
      }
      
      while(!q.empty())
      {
          int i =q.front().first;
          int j=q.front().second;
          
          q.pop();
          
         for(int k=0;k<4;k++)
        {
            int x=i+deltarow[k];
            int y=j+deltacol[k];
            
            if(x>=0 && x<n && y>=0 && y<m && !visi[x][y] && grid[x][y]==1)
            {
              q.push({x,y});
              visi[x][y]=1;
            }
        }
          
      }
      
      
      
      int count=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(!visi[i][j] && grid[i][j]==1)
              {
                  count++;
              }
          }
      }
        return count;
    }
