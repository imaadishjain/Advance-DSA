//Link-https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;


 //Memoization
 int solve(int n, int m ,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        //Base Condition
        if(n==0 && m==0)
        {
            return grid[n][m];
        }
        if(n<0 || m<0)
        {
            return 1e7;
        }


        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int up=grid[n][m]+solve(n-1,m,grid,dp);
        int left=grid[n][m]+solve(n,m-1,grid,dp);

        return dp[n][m]=min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,grid,dp);
    }


// Tabulation
int minPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        
        //Base Condition
       dp[0][0]=grid[0][0];
       

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(i-1>=0)
             {
           dp[i][j]=min(dp[i][j],grid[i][j]+dp[i-1][j]);
             }
            if(j-1>=0)
            {
             dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j-1]);
            }
        }
       }
       return dp[n-1][m-1];
    }