//Link-https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup


#include<bits/stdc++.h>
using namespace std;



int deltrow[3]={1,1,1};
    int deltcol[3]={-1,0,1};
    int chocolate(int i, int j1, int j2,int n, int m, vector<vector<int>>grid,vector<vector<vector<int>>>&dp)
    {
        if(i>=n || j1<0 || j2<0 || j1>=m || j2>=m)
        {
            return -1e9;
        }
        
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int ans=-1e9;
        int gain=0;
        if(j1==j2)
        {
            gain+=grid[i][j1];
        }
        else
        {
            gain+=grid[i][j1]+grid[i][j2];
        }
       
        for(int p=0;p<3;p++)
        {   
            for(int q=0;q<3;q++)
            {
                int move=gain+chocolate(i+1,j1+deltcol[p],j2+deltcol[q],n,m,grid,dp);
                ans=max(ans,move);
            }
        }
        
        return dp[i][j1][j2]=ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
       
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
       
      return chocolate(0,0,m-1,n,m,grid,dp);
    }