#include<bits/stdc++.h>
using namespace std;


// User function Template for C++

class Solution{
public:
      int deltarow[4]={-1,0,1,0};
      int deltacol[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<bool>>&visi,vector<vector<char>>mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        visi[i][j]=true;
        
 
        for(int k=0;k<4;k++)
        {
            int x=i+deltarow[k];
            int y=j+deltacol[k];
            
            if(x>=0 && x<n && y>=0 && y<m  && !visi[x][y] && mat[x][y]=='O')
            {
                
                dfs(x,y,visi,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<bool>>visi(n,vector<bool>(m,false));
       
       for(int i=0;i<n;i++)
       {
           if(!visi[i][0] && mat[i][0]=='O')
           {
               dfs(i,0,visi,mat);
           }
           if(!visi[i][m-1] && mat[i][m-1]=='O')
           {
               dfs(i,m-1,visi,mat);
           }
       }
       
        for(int j=0;j<m;j++)
       {
           if(!visi[0][j] && mat[0][j]=='O')
           {
               dfs(0,j,visi,mat);
           }
           if(!visi[n-1][j] && mat[n-1][j]=='O')
           {
               dfs(n-1,j,visi,mat);
           }
       }
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(!visi[i][j] && mat[i][j]=='O') 
               {
                   mat[i][j]='X';
               }
           }
       }
       
       return mat;
       
    }
};