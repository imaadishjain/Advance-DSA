#include<bits/stdc++.h>
using namespace std;




void dfs(int i, int j,int br, int bc,vector<vector<int>>&grid,vector<vector<bool>>&visi,vector<pair<int,int>>&vec)
     {
         
         int deltarow[] = {-1, 0, +1, 0}; 
          int deltacol[] = {0, -1, 0, +1}; 

         visi[i][j]=true;
         vec.push_back({i-br,j-bc});
         int n=grid.size();
         int m=grid[0].size();
         for(int k=0;k<4;k++)
         {
             int row=i+deltarow[k];
             int col=j+deltacol[k];
             
             if(row>=0 && row<n && col>=0 && col<m && !visi[row][col] &&  grid[row][col]==1)
             {
                
                 dfs(row,col,br,bc,grid,visi,vec);
             }
         }
     }
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visi(n,vector<bool>(m,false));
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              
                if(!visi[i][j] && grid[i][j]==1)
                {
                     vector<pair<int,int>>vec;
                    dfs(i,j,i,j,grid,visi,vec);
                    st.insert(vec);
                }
            }
        }
        
        
        
        return st.size();
    }